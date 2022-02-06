//#define DBG
typedef vector<int> vi;

class Solution {
#ifdef DBG
    void print(vi& nums){
        int n=nums.size();
        for(int i=0;i<n;i++)
            cout<<nums[i]<<" ";
        cout<<endl;
    }
#endif
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(),i=0,ub;
        int n_=n;
        vi temp(n);
        while(i<n){
            if(i+1<n && nums[i+1]==nums[i]){
                ub=i+2;
                while(ub<n && nums[ub]==nums[i])
                {   
                    nums[ub++]=INT_MAX;
                    n_--;
                }//end of while. 
                i=ub;
            }
            else 
                i++;
        }//end of outer while.
#ifdef DBG 
        printf("__Sz[%d]__\n",n_);
        print(nums);
#endif
        int temp_=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=INT_MAX)
                temp[temp_++]=nums[i];
        }
        for(int i=0;i<n_;i++)
            nums[i]=temp[i];
        return n_;
    }
};