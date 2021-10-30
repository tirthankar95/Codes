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
const int mxSize=1e4+1;
TreeNode pool[mxSize];
int poolPtr;
class Solution {
    vector<TreeNode*> fn(int lb,int ub){
        vector<TreeNode*> ptr;
        if(lb>ub){
            ptr.push_back(NULL);
            return ptr;
        }
        for(int i=lb;i<=ub;i++)
        {
            vector<TreeNode*> lNode=fn(lb,i-1);
            vector<TreeNode*> rNode=fn(i+1,ub);
            int lsz=lNode.size();
            int rsz=rNode.size();
            for(int j=0;j<lsz;j++)
            {
                for(int k=0;k<rsz;k++)
                {
                    TreeNode* root=&pool[poolPtr];
                    poolPtr=(poolPtr+1)%mxSize;
                    root->val=i;
                    root->left=lNode[j];
                    root->right=rNode[k];
                    ptr.push_back(root);
                }
            }//end of for-j.
        }
        return ptr;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        poolPtr=0;
        vector<TreeNode*> ans=fn(1,n);
        return ans;
    }
};