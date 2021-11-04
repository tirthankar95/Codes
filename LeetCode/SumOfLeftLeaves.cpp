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
    int sum;
    void fn(TreeNode* root)
    {
        if(!root)return; 
        if(root->left)
        {
            TreeNode* tmp=root->left;
            if(tmp->left==NULL && tmp->right==NULL)
                sum+=tmp->val;
        }
        fn(root->left);
        fn(root->right);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        sum=0;
        fn(root);
        return sum;
    }
};