class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0,n=nums.size();
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i+1]==nums[i])continue;
            else 
                ans+=(nums[i+1]-nums[i])*(n-1-i);
        }
        return ans;
    }
};
we can know every time increasing n-1 elements by 1 equals to decreasing 1 elements by 1, so we just need to move every element equals to minimum element of array.

class Solution:
    def minMoves(self, nums: List[int]) -> int:
        res = 0
        minnum = min(nums)
        for item in nums:
            res += (item - minnum)
        return res