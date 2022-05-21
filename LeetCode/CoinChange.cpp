//#define DBG
const int MX_AMT=1e4+1;
int dp[MX_AMT];

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        memset(dp,0,sizeof(amount+1));
        if(!amount)return amount;
        for(int i=1;i<=amount;i++){
            dp[i]=INT_MAX;
            for(int j=0;j<n;j++){
                if(i<coins[j])break;
                if(dp[i-coins[j]]==INT_MAX)continue;
                dp[i]=min(dp[i],1+dp[i-coins[j]]);
            }
        }//end of outer for.
#ifdef DBG
        for(int i=1;i<=amount;i++)
            cout<<i<<" "<<dp[i]<<endl;
        cout<<endl;
#endif 
        return (dp[amount]==INT_MAX)?-1:dp[amount];
    }
};