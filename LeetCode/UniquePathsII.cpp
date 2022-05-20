typedef vector<int> vi;
typedef vector<vi> vvi;
static int dir[4][2]={{1,0},{0,1}};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int r=obs.size();
        int c=obs[0].size();
        vvi dp(r,vi(c,0));
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        queue<int> Q;
        if(!obs[0][0]){
            Q.push(0);
            dp[0][0]=1;
        }
        int src_i,src_j,c_i,c_j;
        while(!Q.empty()){
            src_i=Q.front()/c;
            src_j=Q.front()%c;
            Q.pop();
            for(int d=0;d<2;d++){
                c_i=src_i+dir[d][0];
                c_j=src_j+dir[d][1];
                if(c_i<0 || c_i>=r || c_j<0 || c_j>=c || obs[c_i][c_j])continue;
                dp[c_i][c_j]+=dp[src_i][src_j];
                if(!vis[c_i][c_j])
                {
                    vis[c_i][c_j]=true;
                    Q.push(c_i*c+c_j);
                }
            }
        }//end of while.
        return dp[r-1][c-1];
    }
};
/* Second Solution*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        vector<vector<int>> dp(r,vector<int>(c,0));
        dp[0][0]=(mat[0][0])?0:1;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j])continue;
                dp[i][j]+=(i-1>=0)?dp[i-1][j]:0;
                dp[i][j]+=(j-1>=0)?dp[i][j-1]:0;
            }
        }//end of outer-for.
        return dp[r-1][c-1];
    }
};
