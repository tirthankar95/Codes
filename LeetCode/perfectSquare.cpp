class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        dp[0]=0;dp[1]=1;
        float tmp;
        for(int i=2;i<=n;i++)
            dp[i]=INT_MAX;
        for(int i=2;i<=n/2;i++)
            if(i*i<=n)dp[i*i]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=sqrt(i);j++)
            {
                dp[i]=min(dp[i],dp[j*j]+dp[i-j*j]);
            }
        }
        return dp[n];
    }
};