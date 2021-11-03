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
    void fn(TreeNode* root,int no){
        if(!root)return;
        no=no*10+root->val;
        if(root->left==NULL && root->right==NULL){
            sum+=no;
            return;
        }
        fn(root->left,no);
        fn(root->right,no);
    }
public:
    int sumNumbers(TreeNode* root) {
        sum=0;
        fn(root,0);
        return sum;
    }
};