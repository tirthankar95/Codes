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
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root)return root;
        if(low<=root->val && root->val<=high){
            root->left=trimBST(root->left,low,high);
            root->right=trimBST(root->right,low,high);
            return root;
        }
        if(low>root->val)
            return trimBST(root->right,low,high);
        if(high<root->val)
            return trimBST(root->left,low,high);
        return root;
    }
};