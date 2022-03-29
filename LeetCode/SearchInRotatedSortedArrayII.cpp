//#define DBG
typedef vector<int> vi;

class Solution {
    int pivot;
    bool binSearch(vi& nums,int lb,int ub,int target){
        int mid;
        while(lb<=ub){
            mid=lb+(ub-lb)/2;
            if(nums[mid]==target)
                return true;
            if(nums[mid]<target)
                lb=mid+1;
            else 
                ub=mid-1;
        }
        return false;
    }
    void getPivot(vi& nums,int lb,int ub){
        if(lb<=ub){
            int mid=lb+(ub-lb)/2;
            if(nums[0]<nums[mid])
                getPivot(nums,mid+1,ub);
            else
            {
                pivot=(mid-1>=0 && nums[mid-1]>nums[mid])?mid:pivot;
                if(nums[mid]>=nums[ub])
                    getPivot(nums,mid+1,ub);
                getPivot(nums,lb,mid-1);
            }
        }
    }
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        pivot=0;
        getPivot(nums,0,n-1);
#ifdef DBG
        cout<<"Pivot -> "<<pivot<<endl;
#endif
        if(nums[pivot]<=target && target<=nums[n-1])
            return binSearch(nums,pivot,n-1,target);
        else 
            return binSearch(nums,0,pivot-1,target);
    }
};