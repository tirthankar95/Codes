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
// const int mxSize=3001;
// TreeNode pool[mxSize];
// int poolPtr=0;
// TreeNode* getNode(int val){
//     TreeNode* tmp=&pool[poolPtr];
//     poolPtr=(poolPtr+1)%mxSize;
//     tmp->left=NULL;tmp->right=NULL;
//     tmp->val=val;
//     return tmp;
// }
typedef vector<int> vi;
class Solution {
    unordered_map<int,int> hMap;
    TreeNode* build(vi& inorder,int lbI,int ubI,vi& postorder,int& ubP){
        if(lbI>ubI)return NULL;
        TreeNode* r=new TreeNode(postorder[ubP]);
        int i=hMap[postorder[ubP]];
        ubP--;
        r->right=build(inorder,i+1,ubI,postorder,ubP);
        r->left=build(inorder,lbI,i-1,postorder,ubP);
        return r;
    }
public:
    TreeNode* buildTree(vi& inorder, vi& postorder) {
        int N=postorder.size()-1;
        int NP=N;
        for(int i=0;i<=N;i++)hMap[inorder[i]]=i;
        return build(inorder,0,N,postorder,NP);
    }
};