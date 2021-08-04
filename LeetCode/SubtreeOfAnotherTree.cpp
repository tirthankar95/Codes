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
    bool dfs(TreeNode* root,TreeNode* subRoot)
    {
        if(root==NULL && subRoot==NULL)return true;
        else if((root==NULL && subRoot!=NULL)||(root!=NULL && subRoot==NULL))return false;
        if(root->val==subRoot->val)
        {
            return dfs(root->left,subRoot->left)&dfs(root->right,subRoot->right);
        }
        return false;
    }
    bool dfsParent(TreeNode* root,TreeNode* subRoot)
    {
        if(root==NULL)return false;
        if(root->val==subRoot->val && dfs(root,subRoot))
            return true;
        return dfsParent(root->left,subRoot)|dfsParent(root->right,subRoot);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfsParent(root,subRoot);
    }
};