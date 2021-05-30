const int mxSize=31;
int count_[mxSize][2];

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n=nums.size();
        memset(count_,0,2*mxSize*sizeof(int));
        for(int i=0;i<n;i++)
        {
            int mask=0x1;
            for(int j=0;j<mxSize;j++)
            {
                count_[j][(bool)(nums[i]&mask)]++;
                mask<<=1;
            }//end of inner-j.
        }//end of outer-j.
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int mask=0x1;
            for(int j=0;j<mxSize;j++)
            {
                ans+=count_[j][!(bool)(nums[i]&mask)];
                mask<<=1;
            }//end of inner-j.
        }
        return ans/2;
    }
};
/*
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        int mask = 1;
        for(int i = 0;i < 31;i++){
            int zeros = 0,ones = 0;
            for(int j = 0;j < nums.size();j++){
                int temp = nums[j] & mask;
                if(temp >= 1)ones++;
                else zeros++;
            }
            ans += (ones * zeros);
            mask <<=1;
        }
        return ans;
    }
};
*/