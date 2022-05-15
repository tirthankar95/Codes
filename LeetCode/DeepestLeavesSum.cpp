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
    int height(TreeNode* r){
        if(!r)return 0;
        return 1+max(height(r->left),height(r->right));
    }
    void dfs(TreeNode* r,int ht){
        if(!r)return;
        if(ht==1)sum+=r->val;
        dfs(r->left,ht-1);
        dfs(r->right,ht-1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        int ht=height(root);
        sum=0;
        dfs(root,ht);
        return sum;
    }
};