
/**** MY SOLUTUION ****/
typedef long long ll;
typedef vector<int> vi;
inline ll max_(ll a,ll b){
    return ((a>b)?a:b);
}
inline ll min_(ll a,ll b){
    return ((a>b)?b:a);
}

class Solution {
    int n,res;
    bool isValid(vi& nums,ll limit_){
        ll mi=INT_MAX;ll mx=INT_MIN;
        ll var;
        for(int i=0;i<n;i++){
            if(nums[i]%2){
                if(nums[i]>limit_)return false;
                var=((ll)nums[i]*(ll)2<=limit_)?(ll)nums[i]*(ll)2:nums[i];
            }
            else{
                var=nums[i];
                while(var%2==0 && var>limit_)var/=2;
                if(var%2==1 && var>limit_)return false;
            }
            mi=min_(mi,var);
            mx=max_(mx,var);
        }
        res=min_(res,mx-mi);
        return true;
    }
public:
    int minimumDeviation(vector<int>& nums) {
        n=nums.size(),res=INT_MAX;
        ll lb,ub=nums[0];
        for(int i=1;i<n;i++){
            ub=max_(ub,nums[i]);
            if(nums[i]%2)
                ub=max_(ub,(ll)nums[i]*(ll)2);
        }
        ll temp=ub,mid;
        while(!(temp & 0x1))temp/=2;
        lb=temp;
        while(lb<=ub){
            mid=(lb+ub)/2;
            if(isValid(nums,mid)){
                ub=mid-1;
            }
            else lb=mid+1;
        }//end of while.
        return res;
    }
};

/**** Priority Queue & hashset ****/
https://leetcode.com/problems/minimize-deviation-in-array/discuss/1781709/C%2B%2B-oror-Easy-oror-2-Approaches-oror-Priority-Queue-oror-Set