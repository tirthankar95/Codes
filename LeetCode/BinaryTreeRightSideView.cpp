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
typedef vector<int> vi;
class Solution {
    int getHeight(TreeNode* root){
        if(!root)return 0;
        return 1+max(getHeight(root->left),getHeight(root->right));
    }
    void fn(TreeNode* root,vi& sol,int lvl){
        if(!root)return;
        sol[lvl]=root->val;
        fn(root->left,sol,lvl+1);
        fn(root->right,sol,lvl+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vi sol(getHeight(root));
        fn(root,sol,0);
        return sol;
    }
};