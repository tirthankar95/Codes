#define ll long long
class Solution {
public:

    ll dp[504][504];
    vector<int> nums;
    int n;
    
    ll simul(int l,int r)
    {
        if(l>=r)return 0;
        if(dp[l][r]!=-1)
            return dp[l][r];
        ll temp=0;
        
        for(int i=l+1;i<r;i++)
        {
            ll prev=nums[l];
            ll next=nums[r];
            temp=max(temp,(prev*next*nums[i])+simul(l,i)+simul(i,r) );
        }
        return dp[l][r]=temp;
    }
    
    
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        this->nums=nums;
        this->nums.push_back(1);
        this->nums.insert(this->nums.begin(),1);
        n=this->nums.size();
        
        return simul(0,n-1);
    }
};
