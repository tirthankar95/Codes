class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb=0,ub=nums.size()-1,mid;
        bool found=false;
        int lIndx=-1,fIndx=-1;
        while(lb<=ub){
            mid=(lb+ub)/2;
            if(nums[mid]==target)found=true;
            if(nums[mid]>target)ub=mid-1;
            else lb=mid+1;
        }
        if(found)lIndx=ub;
        lb=0;ub=nums.size()-1;
        while(lb<=ub){
            mid=(lb+ub)/2;
            if(nums[mid]>=target)ub=mid-1;
            else lb=mid+1;
        }
        if(found)fIndx=lb;
        vector<int> sol({fIndx,lIndx});
        return sol;
    }
};