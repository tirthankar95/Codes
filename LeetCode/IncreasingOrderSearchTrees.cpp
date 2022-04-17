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
const int mxSize=1e3+1;
TreeNode pool[mxSize];
int tree_node_ptr;

class Solution {
    TreeNode* gR;
    TreeNode* create(int val){
        TreeNode* temp=&pool[tree_node_ptr++];
        temp->val=val;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    void fn(TreeNode* root,TreeNode** r){
        if(!root)
            return;
        fn(root->left,r);
        if(!gR){
            *r=create(root->val);
            gR=*r;
        }
        else{
            (*r)->right=create(root->val);
            (*r)=(*r)->right;
        }
        fn(root->right,r);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        tree_node_ptr=0;
        gR=NULL;
        TreeNode* dummy=new TreeNode;
        fn(root,&dummy);
        return gR;
    }
};