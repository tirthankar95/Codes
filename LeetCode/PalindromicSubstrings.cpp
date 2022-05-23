const int mxSize=1e3+1;
int dp[mxSize][mxSize];

class Solution {
    void clear(int n){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dp[i][j]=0;
    }
public:
    int countSubstrings(string s){
        int n=s.length();
        clear(n);
        int cnt=0;
        for(int len=0;len<n;len++)
        {
            for(int j=0;j+len<n;j++){
                if(len==0){
                    dp[j][j]=1;
                    cnt++;
                    continue;
                }//
                if(len==1 && s[j]==s[j+len]){
                    dp[j][j+len]=1;
                    cnt++;
                    continue;
                }//
                if(s[j]==s[j+len] && dp[j+1][j+len-1])
                {
                    dp[j][j+len]=dp[j+1][j+len-1];
                    cnt++;
                }
            }
        }
        return cnt;
    }//end of countSubstrings.
};

