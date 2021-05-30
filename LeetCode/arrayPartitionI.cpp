class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int val=0;
        for(int i=n-1;i>=0;i-=2)
        {
            val+=nums[i-1];
        }
        return val;
    }
};