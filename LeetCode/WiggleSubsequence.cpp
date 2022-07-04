const int mxSize=1e3+1;
int dp[2][mxSize];

class Solution {
    void init(int n){
        for(int i=0;i<n;i++)
            dp[0][i]=dp[1][i]=1;
    }
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        init(n);
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i])
                    dp[0][i]=max(dp[0][i],1+dp[1][j]);
                else if(nums[j]>nums[i])
                    dp[1][i]=max(dp[1][i],1+dp[0][j]);
            }//j
            mx=max(mx,max(dp[0][i],dp[1][i]));
        }//i
        return mx;
    }
};