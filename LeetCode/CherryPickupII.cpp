typedef vector<int> vi;
typedef pair<int,int> ii;
const int mxSize=71;
int dp[mxSize][mxSize][mxSize];

class Solution {
    int R,C;
    int dfs(vector<vi>& grid,ii r1,ii r2){
        if(r1.first==R)return 0;
        if(dp[r1.first][r1.second][r2.second]!=-1)
            return dp[r1.first][r1.second][r2.second];
        int mxSum=0,sum=grid[r1.first][r1.second]+grid[r2.first][r2.second];
        for(int i=-1;i<=1;i++){
            if(r1.second+i<0 || r1.second+i>=C)continue;
            for(int j=-1;j<=1;j++){
                if(r2.second+j<0 || r2.second+j>=C)continue;
                if(r1.second+i==r2.second+j)continue;
                mxSum=max(mxSum,
                          dfs(grid,ii(r1.first+1,r1.second+i),ii(r2.first+1,r2.second+j)));
            }
        }//end of for-i.
        return (dp[r1.first][r1.second][r2.second]=(sum+mxSum));
    }
public:
    int cherryPickup(vector<vi>& grid) {
        R=grid.size();
        C=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return dfs(grid,ii(0,0),ii(0,C-1));
    }
};