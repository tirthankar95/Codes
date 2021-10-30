typedef vector<int> vi;
const int mxSize=1e5+1;
vi lr_small(mxSize);
vi rl_big(mxSize);
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        lr_small[0]=prices[0];rl_big[n-1]=prices[n-1];
        for(int i=1;i<n;i++)
        {
            lr_small[i]=min(lr_small[i-1],prices[i]);
            rl_big[n-1-i]=max(rl_big[n-i],prices[n-1-i]);
        }
        int ans=prices[n-1]-prices[0];
        int fpart=0;int spart=0;
        for(int i=0;i<n-1;i++){
            if(prices[i]>prices[i+1])
            {
                fpart=max(fpart,prices[i]-lr_small[i]);
                spart=rl_big[i+1]-prices[i+1];
                ans=max(ans,fpart+spart);
            }
        }//end of for. 
        return ans;
    }
};