typedef long long ll;
struct megaNode{
    ll min_;
    ll max_;
    bool isBst;
    megaNode(ll min_,ll max_,bool isBst):min_(min_),max_(max_),isBst(isBst){}
};
class Solution {
    megaNode* fn(TreeNode* root){
        if(root==NULL)
            return new megaNode(LONG_MAX,LONG_MIN,true);
        megaNode* l=fn(root->left);
        megaNode* r=fn(root->right);
        if(!(l->isBst && r->isBst && l->max_<root->val && root->val<r->min_))
            return new megaNode(LONG_MIN,LONG_MAX,false);
        else
            return new megaNode(min((ll)root->val,l->min_),max((ll)root->val,r->max_),true);
    }
public:
    bool isValidBST(TreeNode* root) {
        megaNode* res=fn(root);
        return res->isBst;
    }
};

/* 1 Line Python Code*/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode],left=-inf,right=inf) -> bool:
        return (not root) or ((left<root.val<right) and self.isValidBST(root.left,left,root.val) and self.isValidBST(root.right,root.val,right))