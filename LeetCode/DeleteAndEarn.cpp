const int mxSize=1e4+1;
int freq[mxSize+1];
int dp[mxSize+1];

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        memset(freq,0,sizeof(freq));
        memset(dp,0,sizeof(dp));
        int n=nums.size(),mx=-1,temp;
        for(int i=0;i<n;i++)
            freq[nums[i]]++,mx=max(mx,nums[i]);
        for(int i=1;i<=mx;i++){
            temp=(i-2>0)?dp[i-2]:0;
            dp[i]=max(i*freq[i]+temp,dp[i-1]);
        }
        return dp[mx];
    }
};