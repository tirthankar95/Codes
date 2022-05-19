//#define DBG
typedef vector<int> vi;
typedef vector<vi> vvi;
static int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
class Solution {
    int R,C;
    void dfs(int parentIndex,int src,vvi& matrix,vvi& dp){
        int i=src/C;
        int j=src%C;
        int ic,jc;
        dp[i][j]=1;
        for(int d=0;d<4;d++){
            ic=i+dir[d][0];
            jc=j+dir[d][1];
            if(ic<0 || jc<0 || ic>=R || jc>=C || (ic*C+jc==parentIndex))continue;
            if(!dp[ic][jc] && matrix[i][j]<matrix[ic][jc])
            {
                dfs(i*C+j,ic*C+jc,matrix,dp);
                dp[i][j]=max(dp[i][j],1+dp[ic][jc]);
            }
            else if(matrix[i][j]<matrix[ic][jc])
                dp[i][j]=max(dp[i][j],1+dp[ic][jc]);
        }
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        R=matrix.size();
        C=matrix[0].size();
        vvi dp(R,vi(C,0));
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(!dp[i][j])
                    dfs(-1,i*C+j,matrix,dp);
            }
        }//end of outer loop.
        int mx=1;
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
#ifndef DBG
                mx=max(mx,dp[i][j]);
#else
            {
                mx=max(mx,dp[i][j]);
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
#endif
        }

        return mx;
    }
};