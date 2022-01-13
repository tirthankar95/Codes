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
    int tot_sum;
    void dfs(TreeNode* root,int temp){
        if(!root)return;
        temp=temp*2+root->val;
        if(root->left==NULL && root->right==NULL){
            tot_sum+=temp;
            return;
        }
        dfs(root->left,temp);
        dfs(root->right,temp);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        tot_sum=0;
        int temp=0;
        dfs(root,temp);
        return tot_sum;
    }
};