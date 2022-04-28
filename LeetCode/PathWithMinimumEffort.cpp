typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
const int mxHt = 1e6 + 1;
const int mxSize = 1e2 + 1;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size(), c = heights[0].size();
        int lb = 0, ub = mxHt;
        int res = INT_MAX,child_x,child_y,possible;
        while (lb <= ub) {
            int mid = (lb + ub) / 2;
            {
                possible = false;
                vector<vector<bool>> vis(mxSize, vector<bool>(mxSize, false));
                queue<ii> Q;
                
                Q.push(ii(0, 0)); vis[0][0] = true;
                while (!Q.empty()) {
                    ii src = Q.front();
                    Q.pop();
                    for (int i = 0; i < 4; i++) {
                        child_x = src.first + dir[i][0];
                        child_y = src.second + dir[i][1];
                        if (child_x < 0 || child_x >= r || child_y<0 || child_y >= c || vis[child_x][child_y] || abs(heights[src.first][src.second] - heights[child_x][child_y])>mid)continue;
                        if (child_x == r - 1 && child_y == c - 1)
                        {
                            possible = true;
                            break;
                        }
                        Q.push(ii(child_x, child_y));
                        vis[child_x][child_y] = true;
                    }//end of for.
                    if (possible) {
                        while (!Q.empty())Q.pop();
                    }
                }//end of while.
            }//end of block.
            if (possible) {
                res = mid;
                ub = mid - 1;
            }
            else lb = mid + 1;
        }//end of bin-search while.
        return res;
    }
};