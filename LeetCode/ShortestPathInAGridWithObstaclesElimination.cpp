const int mxSize=41;
int vis[mxSize][mxSize];
typedef vector<vector<int>> vvi;
static int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
struct state{
    int i_;
    int j_;
    int k_;
    int cnt;
};

class Solution {
    int R,C;
public:
    int shortestPath(vvi& grid, int k) {
        R=grid.size();
        C=grid[0].size();
        if(R==1 && C==1)return 0;
        memset(vis,-1,sizeof(vis));
        queue<state> qu;
        qu.push(state({0,0,k,0}));
        vis[0][0]=k;
        while(!qu.empty()){
            state src=qu.front();
            qu.pop();
            for(int i=0;i<4;i++)
            {
                int i__=src.i_+dir[i][0];
                int j__=src.j_+dir[i][1];
                if(i__<0 || j__<0 || i__>=R || j__>=C)continue;
                if(i__==R-1 && j__==C-1)return src.cnt+1;       
                if(!grid[i__][j__]){
                    if(vis[i__][j__]<src.k_)
                    {
                        vis[i__][j__]=src.k_;
                        qu.push(state{i__,j__,src.k_,src.cnt+1});
                    }
                }
                else if(src.k_){
                    if(vis[i__][j__]<src.k_-1)
                    {
                        vis[i__][j__]=src.k_-1;
                        qu.push(state{i__,j__,src.k_-1,src.cnt+1});
                    }
                }
            }//end  of for.
        }
        return -1;
    }
};