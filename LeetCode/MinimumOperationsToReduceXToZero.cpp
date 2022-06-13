class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        vector<int> nums2(2*n);
        for(int i2=0;i2<2;i2++)
        {
            for(int i=0;i<n;i++)
                nums2[i2*n+i]=nums[i];
        }
        int fptr=0,sptr=0,mi=INT_MAX,rSum=0;
        while(fptr<n && sptr<2*n){
            if(rSum<=x)
                rSum+=nums2[sptr++];
            else{
                while(fptr<=sptr && rSum>x){
                    rSum-=nums2[fptr++];
                }
            }
            if(x==rSum && (fptr==0 || sptr>=n))
                mi=min(mi,sptr-fptr);
        }//end of while.
        return (mi>n)?-1:mi;
    }
};