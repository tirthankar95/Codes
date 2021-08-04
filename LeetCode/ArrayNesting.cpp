class Solution {
    int mxLen;
    int tmpLen;
    void dfs(vector<int>& nums,int indx,vector<bool>& vis)
    {
        if(vis[indx])return;
        vis[indx]=true;
        tmpLen++;
        dfs(nums,nums[indx],vis);
    }
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        vector<bool> vis(n,false);
        mxLen=1;
        for(int i=0;i<n;i++)
        {
            if(!vis[nums[i]])
            {
                tmpLen=0;
                dfs(nums,i,vis);
                mxLen=max(mxLen,tmpLen);
            }
        }
        return mxLen;
    }
};