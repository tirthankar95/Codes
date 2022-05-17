/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//#define UNIQUE
class Solution {
    TreeNode* res;
#ifdef UNIQUE
    void dfs(TreeNode* cloned,int val){
        if(!cloned)return;
        if(cloned->val==val){
            res=cloned;
            return;
        }
        dfs(cloned->left,val);
        if(res)return;
        dfs(cloned->right,val);
    }
#endif
    void dfs_nu(TreeNode* original,TreeNode* cloned,TreeNode* target){
        if(!cloned)return;
        if(original==target){
            res=cloned;
            return;
        }
        dfs_nu(original->left,cloned->left,target);
        if(res)return;
        dfs_nu(original->right,cloned->right,target);
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
#ifdef UNIQUE
        //Assume unique. 
        res=NULL;
        dfs(cloned,target->val);
        return res;
#endif
        //Assume not unique.
        res=NULL;
        dfs_nu(original,cloned,target);
        return res;
    }
};