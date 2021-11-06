class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=0,diff=0;
        for(int i=0;i<n;i++)sum^=nums[i];
        for(int i=0;i<32;i++)
        {
            if(sum&1)
            {
                diff=1<<i;
                break;
            }
            sum=sum>>1;
        }
        vector<int> res(2);
        for(int i=0;i<n;i++)
        {
            if(diff&nums[i])
                res[0]^=nums[i];
            else 
                res[1]^=nums[i];
        }
        return res;
    }
};