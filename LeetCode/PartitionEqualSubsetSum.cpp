const int dim2=201;
const int dim1=20001;
bool dp[dim1][dim2];
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),sum=0;
        for(int i=0;i<n;i++)sum+=nums[i];
        if(sum%2)return 0;
        sum/=2;
        memset(dp[0],true,(n+1)*sizeof(bool));
        for(int i=1;i<=sum;i++)memset(dp[i],false,(n+1)*sizeof(bool));
        for(int i=1;i<=sum;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i-nums[j-1]>=0)
                    dp[i][j]|=dp[i-nums[j-1]][j-1];
                dp[i][j]|=dp[i][j-1];
            }//end of inner-for.
        }//end of outer-for. 
        return dp[sum][n];
    }
};