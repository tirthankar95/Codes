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
    ii fn(TreeNode* root)
    {
        if(root==NULL)return ii(0,0);
        ii l=fn(root->left);
        ii r=fn(root->right);
        int a=root->val+l.second+r.second;
        int b=max(max(l.first+r.second,l.second+r.first),
                  max(l.first+r.first,l.second+r.second));
        /* 
            why is the last term required "l.second+r.second"(I missed)? 
            Let's say Depth0 & Depth3 gives the biggest result
            TC: [100,1,null,1,1,100,100,100,100]
        */
        return ii(a,b);
    }
public:
    int rob(TreeNode* root) {
        ii r=fn(root);
        return max(r.first,r.second);
    }
};