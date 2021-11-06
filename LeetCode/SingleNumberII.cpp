typedef vector<int> vi;
const int mxSize=32;
int bitCount[mxSize];

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        memset(bitCount,0,sizeof(bitCount));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<mxSize;j++)
            {
                if(nums[i]&1)
                    bitCount[j]++;
                nums[i]=nums[i]>>1;
            }
        }
        int ans=0;
        for(int i=0;i<32;i++)
        {
            if(bitCount[i]%3==1)
                ans=ans|(1<<i);
        }
        return ans;
    }
};