typedef vector<int> vi;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=0;
        int lb=prices[0];
        for(int i=1;i<n;i++)
        {
            if(prices[i]>=prices[i-1])continue;
            else{
                profit+=(prices[i-1]-lb);
                lb=prices[i];
            }
        }
        if(lb<prices[n-1])
            profit+=(prices[n-1]-lb);
        return profit;
    }
};