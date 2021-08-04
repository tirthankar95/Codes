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
    int gSum;
    int dfs(TreeNode* root)
    {
        if(root==NULL)return 0;
        int L=dfs(root->left), R=dfs(root->right);
        gSum+=abs(L-R);
        return root->val+L+R;
    }
public:
    int findTilt(TreeNode* root) {
        gSum=0;
        dfs(root);
        return gSum;
    }
};