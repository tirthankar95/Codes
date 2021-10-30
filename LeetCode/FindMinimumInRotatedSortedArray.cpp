class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int lb=0;int ub=n-1;int mid;
        int mi=nums[0];
        while(lb<=ub)
        {
            mid=(lb+ub)/2;
            if(nums[0]>nums[mid])
            {
                mi=min(mi,nums[mid]);
                ub=mid-1;
            }
            else{
                lb=mid+1;
            }
        }
        return mi;
    }
};