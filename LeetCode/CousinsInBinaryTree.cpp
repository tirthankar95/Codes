/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int xl,yl;
    TreeNode *xp,*yp;
    void dfs(TreeNode* root,int x,int y,int lvl,TreeNode* par)
    {
        if(!root)return;
        if(root->val==x)
        {
            xp=par;
            xl=lvl;
        }
        if(root->val==y)
        {
            yp=par;
            yl=lvl;
        }
        dfs(root->left,x,y,lvl+1,root);
        dfs(root->right,x,y,lvl+1,root);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root,x,y,0,root);
        return (xl==yl && xp!=yp);
    }
};