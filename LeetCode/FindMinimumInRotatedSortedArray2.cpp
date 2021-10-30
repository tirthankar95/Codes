class Solution {
public:
    int findMin(vector<int>& nums) {
        int lb=0,ub=nums.size()-1,mid;
        int mi=nums[0];
        if(lb==ub || nums[lb]<nums[ub])return mi;
        while(lb<=ub)
        {
            mid=(lb+ub)/2;
            mi=min(mi,nums[mid]);
            if(nums[lb]>nums[mid])// first-part of array.
                ub=mid-1;
            else if(nums[mid]>nums[ub])// last-part of array.
                lb=mid+1;
            else
            {
                if(nums[lb]==nums[mid] && nums[mid]>nums[ub])lb=mid+1;
                else if(nums[mid]==nums[ub] && nums[lb]>nums[mid])ub=mid-1;
                else{ 
                    // if all elements are same nums[lb]==nums[mid]==nums[ub]. Traverse everything.
                    for(int iter=lb;iter<=ub;iter++)
                        mi=min(mi,nums[iter]);
                    return mi;
                }
            }
        }//end of while.
        return mi;
    }
};