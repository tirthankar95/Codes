typedef vector<int> vi;
// Sign.
// 1 -> is positive.
// 0 -> is negative.

const int mxSize=5000;
bool vis[mxSize];
class Solution {
    int N,sign;
    bool dfs(int src,vi& nums)
    {
        if(nums[src]%N==0 || (sign==1 && nums[src]<=0) || (sign==0 && nums[src]>=0))return false;
        int child=((src+nums[src])%N+N)%N;
        if(vis[child])return true;
        vis[src]=true;
        if(dfs(child,nums))
        {
            vis[src]=false;
            return true;
        }
        vis[src]=false;
        nums[src]=N;
        return false;
    }
public:
    bool circularArrayLoop(vector<int>& nums) {
        N=nums.size();
        for(int i=0;i<N;i++)vis[i]=false;
        sign=1;
        for(int i=0;i<N;i++)
        {
            if(nums[i]>0 && dfs(i,nums))
                return true;
        }
        sign=0;
        for(int i=0;i<N;i++)
        {
            if(nums[i]<0 && dfs(i,nums))
                return true;
        }        
        return false;
    }
};