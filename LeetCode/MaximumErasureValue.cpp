const int mxSize=1e4+1;
bool hashMap[mxSize];

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int fptr=0;int sptr=0;
        int mxRes=INT_MIN;
        while(sptr<n){
            if(hashMap[nums[sptr]]==false){
                hashMap[nums[sptr]]=true;
                sum+=nums[sptr++];
                mxRes=max(mxRes,sum);
            }
            else{
                while(fptr<=sptr && hashMap[nums[sptr]]==true){
                    hashMap[nums[fptr]]=false;
                    sum-=nums[fptr++];
                }
            }
        }//end of while.
        //Resetting memory for future test cases.
        while(fptr<n)hashMap[nums[fptr++]]=false;
        return mxRes;
    }
};