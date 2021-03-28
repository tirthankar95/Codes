typedef vector<int> vi;
const int INT_MAXX=1e9+1;
const int mxSize=1e4+1;
int dp[mxSize];

class Solution {
    int N;
    int fn(int amnt,vi& coins)
    {
        if(amnt==0)return 0;
        if(dp[amnt]!=-1)return dp[amnt];
        int ans=INT_MAXX;
        for(int i=0;i<N;i++)
        {
            if(amnt>=coins[i])
                ans=min(ans,1+fn(amnt-coins[i],coins));
        }
        return dp[amnt]=ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        N=coins.size();
        for(int i=0;i<=amount;i++)dp[i]=-1;
        int res=fn(amount,coins);
        return (res==INT_MAXX)?-1:res;
    }
};