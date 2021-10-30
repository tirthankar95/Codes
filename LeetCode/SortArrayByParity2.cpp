class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int lb=0,i=0,cnt=0;
        int n=nums.size();
        for(;i<n;i++)
        {
            if(nums[i]%2==0){
                swap(nums[lb],nums[i]);
                lb++;
            }
        }//end of for. 
        i=0;
        vector<int> ans(n);
        while(lb<n)
        {
            ans[cnt]=nums[i];
            ans[cnt+1]=nums[lb];
            cnt+=2;
            i++;lb++;
        }
        return ans;
    }
};