class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int tmpCnt=0;
        int mx=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                tmpCnt+=1;
                mx=max(tmpCnt,mx);
            }
            else tmpCnt=0;
        }
        return mx;
    }
};