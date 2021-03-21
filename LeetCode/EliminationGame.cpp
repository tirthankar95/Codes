const int mxSize=1e6+1;
int dp[mxSize];

class Solution {
public:
    int lastRemaining(int n) {
        if(n<mxSize && dp[n]!=0)return dp[n];
        if(n==1)return 1;
        int tmp=((n/2)-(lastRemaining(n/2)-1))*2;
        if(n<mxSize)
        {
            dp[n]=tmp;
            return dp[n];
        }
        return tmp;
    }
};