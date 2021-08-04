const int mxSize=51;
const int MOD=1e9+7;
int dp[mxSize][mxSize][mxSize];

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,0,sizeof(dp));
        int tmp;
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<n;k++)
            {
                dp[0][j][k]+=(j-1>=0)?0:1;
                dp[0][j][k]+=(k-1>=0)?0:1;
                dp[0][j][k]+=(j+1<m)?0:1;
                dp[0][j][k]+=(k+1<n)?0:1;
            }
        }
        for(int i=1;i<maxMove;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<n;k++)
                {
                    tmp=(j-1>=0)?dp[i-1][j-1][k]:0;
                    dp[i][j][k]=(dp[i][j][k]+tmp)%MOD;
                    tmp=(k-1>=0)?dp[i-1][j][k-1]:0;
                    dp[i][j][k]=(dp[i][j][k]+tmp)%MOD;
                    tmp=(j+1<m)?dp[i-1][j+1][k]:0;
                    dp[i][j][k]=(dp[i][j][k]+tmp)%MOD;
                    tmp=(k+1<n)?dp[i-1][j][k+1]:0;
                    dp[i][j][k]=(dp[i][j][k]+tmp)%MOD;
                }//end-k.
            }//end-j.
        }//end-i.
        int ans=0;
        for(int i=0;i<maxMove;i++)
            ans=(ans+dp[i][startRow][startColumn])%MOD;            
        return ans;
    }
};