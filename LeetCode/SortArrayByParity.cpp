class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int lb=0;int ub=0;
        int n=nums.size();
        while(ub<n){
            if(nums[ub]%2==0)
                swap(nums[lb++],nums[ub]);
            ub++;
        }
        return nums;
    }
};