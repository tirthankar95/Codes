typedef vector<int> vi;
class Solution {
public:
    int singleNonDuplicate(vi& nums) {
        int N=nums.size();
        int lb=0;int ub=N-1;
        int a,b;
        while(lb<=ub){
            int mid=(lb+ub)/2;
            if(mid<N-1 && nums[mid+1]==nums[mid]){
                a=mid;
                b=mid+1;
            }//end of if.
            else if(mid>0 && nums[mid-1]==nums[mid]){
                a=mid-1;
                b=mid;
            }//end of else-if.
            else return nums[mid];
            if(a%2)ub=mid-1;
            else lb=mid+1;
        }
        return -1;
    }
};