typedef vector<int> vi;
const int mxn=5001;
int count_[mxn];

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        memset(count_,0,sizeof(int)*mxn);
        int n=nums.size();        
        for(int i=0;i<n;i++)count_[nums[i]]++;
        for(int i=1;i<mxn;i++)count_[i]+=count_[i-1];
        vector<int> output(n);
        for(int i=n-1;i>=0;i--)
        {
            output[count_[nums[i]]-1]=nums[i];
            --count_[nums[i]];
        }
        int f=(n%2)?n/2:(n-1)/2,s=n-1;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)nums[i]=output[f--];
            else nums[i]=output[s--];
        }   
    }
};