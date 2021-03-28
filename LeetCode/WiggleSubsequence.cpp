typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        /*
        0 // +ve sum.
        1 // -ve sum.
        */
        int n=nums.size();
        vvi dp(n,vi(2,1));
        int mx=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]>nums[i])
                    dp[i][0]=max(dp[i][0],1+dp[j][1]);
                else if(nums[j]<nums[i])
                    dp[i][1]=max(dp[i][1],1+dp[j][0]);
            }//end of inner-for. 
            mx=max(mx,max(dp[i][0],dp[i][1]));
        }//end of outer-for. 
        return mx;
    }
};
class Solution {
public:
    int wiggleMaxLength(vector<int>& N) {
        int len = N.size(), i = 1, ans = 1;
        while (i < len && N[i] == N[i-1]) i++;
        if (i == len) return 1;
        bool up = N[i-1] > N[i];
        for (; i < len; i++)
            if ((up && N[i] < N[i-1]) || (!up && N[i] > N[i-1]))
                up = !up, ans++;
        return ans;
    }
};