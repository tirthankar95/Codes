const int mxSize=2;
class TreeNode1{
    public:
    bool isLeaf;
    TreeNode1* children[mxSize];
    TreeNode1()
    {
        this->isLeaf=false;
        for(int i=0;i<mxSize;i++)this->children[i]=NULL;
    }
};

void insert(TreeNode1*& root,int no){
    int m;
    TreeNode1* iter=root;
    int mask=1<<30;
    for(int i=31;i>0;i--)
    {
        m=(bool)(mask&no);
        mask=mask>>1;
        if(iter->children[m]==NULL)
            iter->children[m]=new TreeNode1();
        iter=iter->children[m];
    }//end of for.
    iter->isLeaf=true;
}
int findMax(TreeNode1*& root,int no)
{
    int m,ans=0;
    TreeNode1* iter=root;
    int mask=1<<30;
    for(int i=31;i>0;i--)
    {
        m=(bool)(mask&no);
        mask=mask>>1;
        ans=ans<<1;
        if(iter->children[(1-m)]!=NULL)
        {
            ans|=(1-m);
            iter=iter->children[(1-m)];
        }
        else 
        {
            ans|=(m);
            iter=iter->children[m];
        }
    }
    return ans;
}
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        TreeNode1* root=new TreeNode1();
        for(int i=0;i<n;i++)
            insert(root,nums[i]);
        int mx=0;
        for(int i=0;i<n;i++)
            mx=max(mx,nums[i]^findMax(root,nums[i]));
        return mx;
    }
};