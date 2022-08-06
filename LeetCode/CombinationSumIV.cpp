typedef long long ll;
typedef vector<ll> vi;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vi dp(target+1);
        sort(nums.begin(),nums.end());
        dp[0]=1;
        for(int j=1;j<=target;j++){
            dp[j]=0;
            for(int k=0;k<n;k++)
            {
                if(dp[j]>=(ll)UINT_MAX){
                    dp[j]=0;
                    break;
                }
                if(j-nums[k]>=0)
                    dp[j]+=dp[j-nums[k]];
                else 
                    break;
            }
        }
        return dp[target];
    }
};