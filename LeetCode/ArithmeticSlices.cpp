class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<int> diff(n-1);        
        for(int i=1;i<n;i++)
            diff[i-1]=nums[i]-nums[i-1];
        int iter=1,len=0,ans=0;
        while(iter<n-1)
        {
            if(diff[iter-1]==diff[iter])len++;
            else{
                ans+=(len*(len+1))/2;
                len=0;
            }
            iter++;
        }
        ans+=(len*(len+1))/2;
        return ans;
    }
};