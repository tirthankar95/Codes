const int mxSize=1e4+1;
typedef long long ll;
ll dp[mxSize][mxSize];

class Solution {
public:
    int numDistinct(string s, string t) {
        int m=s.length();
        int n=t.length();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                dp[i][j]=0;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=i;j<m;j++)
            {
                if(t[i]==s[j])
                {
                    if(i==0){
                        cnt++;
                        dp[i][j]=cnt;
                    }
                    else{
                        cnt+=(j==0)?1:dp[i-1][j-1];
                        dp[i][j]=cnt;
                    }
                }
                else dp[i][j]=(j==0)?0:dp[i][j-1];
            }
        }//end of outer for. 
        return dp[n-1][m-1];
    }
};