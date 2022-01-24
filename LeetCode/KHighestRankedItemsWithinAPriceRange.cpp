typedef vector<int> vi;
typedef pair<int,int> ii;
static int delta[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
class Solution {
public:
    vector<vi> highestRankedKItems(vector<vi>& grid, vi& pricing, vi& start, int k) {
        int r=grid.size(),c=grid[0].size();
        ii src=ii(start[0],start[1]),vc;
        queue<ii> Q;
        unordered_map<int,int> dist;
        unordered_map<int,bool> vis;
        Q.push(src);
        dist[src.first*c+src.second]=0;
        vis[src.first*c+src.second]=true;
        vector<vi> sol;
        vector<vi> orderedChild;
        if(grid[src.first][src.second]!=1 && grid[src.first][src.second]>=pricing[0] && grid[src.first][src.second]<=pricing[1])
            orderedChild.push_back(vi{0,grid[src.first][src.second],src.first,src.second});
        while(!Q.empty()){
            ii src=Q.front();
            Q.pop();
            for(int i=0;i<4;i++){
                vc=ii(src.first+delta[i][0],src.second+delta[i][1]);
                if(vc.first>=0 && vc.first<r && vc.second>=0 && vc.second<c && !vis[vc.first*c+vc.second] && grid[vc.first][vc.second]!=0){
                    vis[vc.first*c+vc.second]=true;
                    dist[vc.first*c+vc.second]=dist[src.first*c+src.second]+1;
                    Q.push(vc);
                    if(grid[vc.first][vc.second]!=1 && grid[vc.first][vc.second]>=pricing[0] && grid[vc.first][vc.second]<=pricing[1])
                        orderedChild.push_back(vi{dist[vc.first*c+vc.second],grid[vc.first][vc.second],vc.first,vc.second});
                }//end of outer-if.
            }//end of for-loop.
        }//end of while.
        sort(orderedChild.begin(),orderedChild.end());
        r=orderedChild.size();
        for(int i=0;i<r && i<k;i++)
            sol.push_back(vi{orderedChild[i][2],orderedChild[i][3]});
        return sol;
    }
};