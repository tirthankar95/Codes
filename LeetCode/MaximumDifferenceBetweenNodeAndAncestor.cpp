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
//#define DBG
typedef pair<int,int> ii;
inline int abs_(int a,int b){
    return (a-b>=0)?(a-b):(b-a);
}
class Solution {
    int mxDif;
    ii fn(TreeNode* root){
        if(root==NULL)
            return ii(INT_MAX,INT_MIN);
        if(root->left==NULL && root->right==NULL)
            return ii(root->val,root->val);
        ii mimx_l=fn(root->left);
        ii mimx_r=fn(root->right);
        int mi=min(mimx_l.first,mimx_r.first);
        int mx=max(mimx_l.second,mimx_r.second);
        mxDiff=max(mxDiff,abs_(root->val,mi));
        mxDiff=max(mxDiff,abs_(root->val,mx));
        return ii(min(root->val,mi),max(root->val,mx));
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        mxDiff=-1;
        ii check_=fn(root);
#ifdef DBG
        cout<<check_.first<<" "<<check_.second<<endl;
#endif
        return mxDiff;
    }
};