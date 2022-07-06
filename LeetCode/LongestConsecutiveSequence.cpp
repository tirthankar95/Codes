class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size(),lb,mx=0;
        unordered_map<int,int> dp;
        for(int i=0;i<n;i++)dp[nums[i]]=0;
        for(int i=0;i<n;i++){
            if(dp[nums[i]])continue;
            lb=nums[i];
            while(dp.find(lb-1)!=dp.end() && !dp[lb-1])lb-=1;
            while(lb<=nums[i]){
                dp[lb]=(dp.find(lb-1)==dp.end())?1:dp[lb-1]+1;
                lb++;
            }
            mx=max(dp[nums[i]],mx);
        }
        return mx;
    }
};