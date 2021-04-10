//dp[i]=1 if the current player wins.
//dp[i]=0 if the other player wins. 

vector<int> dp;
class Solution {
    bool fn(int n)
    {
        if(n<0)return false;
        if(n==0)return true;
        if(dp[n]!=-1)return dp[n];
        if(fn(n-1) && fn(n-2) && fn(n-3))
            return dp[n]=false;
        return dp[n]=true;
    }
public:
    bool canWinNim(int n) {
        ///// METHOD 1.
        // dp.resize(n+1,-1);
        // dp[1]=dp[2]=dp[3]=true;
        // return fn(n);
        ///// METHOD 2.
        return (n%4!=0);
    }
};