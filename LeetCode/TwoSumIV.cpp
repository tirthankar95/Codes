class Solution {
    TreeNode* used_1;TreeNode* used_2;TreeNode* mainRoot;
    bool bsearch(TreeNode* root,int k)
    {
        if(root==NULL)return false;
        if(root->val==k && used_1!=root)
            return true;
        if(k<root->val)
            return bsearch(root->left,k);
        else if(k>root->val)
            return bsearch(root->right,k);
        return false;
    }
    bool fn(TreeNode* root,int k)
    {
        if(!root)return false;
        used_1=root;
        if(bsearch(mainRoot,k-root->val))return true;
        used_1=NULL;
        return fn(root->right,k)|fn(root->left,k);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        mainRoot=root;
        used_1=NULL,used_2=NULL;
        bool ans=fn(root,k);
        return ans;
    }
};