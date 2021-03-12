class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)sum^=nums[i];
        int diff=0;int mask=1;
        for(int i=0;i<32;i++)
        {
            if((bool)(sum&mask)==1)
            {
                diff=1<<i;
                break;
            }
            mask=mask<<1;
        }//end of outer-for.
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