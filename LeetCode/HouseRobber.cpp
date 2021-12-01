typedef vector<int> vi;
class Solution {
public:
    int rob(vi& nums) {
        int n=nums.size();
        int mx=-1;
        if(n<=2){
            for(int i=0;i<n;i++)
                mx=max(mx,nums[i]);
            return mx;
        }
        vi dp(n);
        dp[0]=nums[0];dp[1]=nums[1];dp[2]=dp[0]+nums[2];
        for(int i=3;i<n;i++){
            dp[i]=nums[i]+max(dp[i-2],dp[i-3]);
        }
        return max(dp[n-1],dp[n-2]);
    }
};