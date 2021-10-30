const int mxSize=1e5+1;
bool vis[mxSize];
class Solution {
    int n;
    int dfs(vector<int>& nums,int id)
    {
        if(nums[id]<0)return nums[id];
        if(vis[id])return 0;
        
        vis[id]=true;
        nums[id]=-1+dfs(nums,nums[id]);
        vis[id]=false;

        return nums[id];
    }
public:
    int arrayNesting(vector<int>& nums) {
        n=nums.size();
        memset(vis,false,sizeof(bool)*n);
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=0)
                dfs(nums,i);
        }
        int mx=0;
        for(int i=0;i<n;i++)mx=min(mx,nums[i]);
        return -mx;
    }
};