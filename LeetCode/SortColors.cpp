class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lb=0;int z=0;
        int n=nums.size();
        int t=n-1;
        while(lb<=t)
        {
            if(nums[lb]==2)
            {
                if(nums[t]!=2)swap(nums[lb],nums[t]);
                t--;
            }
            if(nums[lb]==0)
                swap(nums[lb++],nums[z++]);
            if(lb<n && nums[lb]==1)lb++;
        }
    }
};