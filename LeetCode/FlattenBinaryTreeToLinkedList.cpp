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
    void flatten(TreeNode* root) {
        if(!root)return;
        TreeNode* lR=root->left;
        flatten(lR);
        root->left=NULL;
        TreeNode* rR=root->right;
        root->right=lR;
        while(lR && lR->right)lR=lR->right;
        flatten(rR);
        if(lR)lR->right=rR;
        else root->right=rR;
    }
};