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
typedef pair<int,int> ii;
class Solution {
    map<TreeNode*,ii> hashMap;
    int mx;
    void gn(TreeNode* root)
    {
        if(!root)return;
        mx=max(mx,hashMap[root].first+hashMap[root].second);
        gn(root->left);
        gn(root->right);
    }
    int fn(TreeNode* root){
        if(!root)return 0;
        if(root->left==NULL && root->right==NULL)
        {
            hashMap[root]=ii(0,0);
            return 1;
        }
        int lh=fn(root->left);
        int rh=fn(root->right);
        hashMap[root]=ii(lh,rh);
        return 1+max(lh,rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        hashMap.clear();
        fn(root);
        mx=0;
        gn(root);
        return mx;
    }
};