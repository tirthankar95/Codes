class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx=0,n=prices.size(),i=0,lb;
        vector<int> temp(n);
        temp[n-1]=prices[n-1];
        for(i=n-2;i>=0;i--)
            temp[i]=max(temp[i+1],prices[i]);
        i=0;
        while(i<n)
        {
            while(i+1<n && prices[i]>=prices[i+1])i++;
            mx=max(mx,temp[i]-prices[i]);
            i++;
        }
        return mx;
    }
};

/*******************************************************/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(!n)return 0;
        int mi=prices[0];
        int mxProfit=0;
        for(int i=1;i<n;i++)
        {
            if(mi<prices[i])
                mxProfit=max(mxProfit,prices[i]-mi);
            else mi=prices[i];
        }
        return mxProfit;
    }
};