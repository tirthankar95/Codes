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
    int cnt;
    int tSum;
    void dfs(TreeNode* root,int rSum,unordered_map<int,int>& hashMap){
        if(hashMap[rSum-tSum])cnt+=hashMap[rSum-tSum];
        hashMap[rSum]++;
        if(root->left)dfs(root->left,rSum+root->left->val,hashMap);
        if(root->right)dfs(root->right,rSum+root->right->val,hashMap);
        hashMap[rSum]--;
        }
public:
    int pathSum(TreeNode* root, int targetSum) {
        cnt=0;
        tSum=targetSum;
        unordered_map<int,int> hashMap;
        hashMap[0]=1;
        if(root)dfs(root,root->val,hashMap);
        return cnt;
    }
};