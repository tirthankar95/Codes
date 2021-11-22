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
Check the explanation below
https://leetcode.com/problems/delete-node-in-a-bst/discuss/1590789/C%2B%2B-Shortest-Recursive-Solution-or-Detailed-Explanation-with-images

class Solution {
    TreeNode* res;
    void dfs(TreeNode* parent,TreeNode* root,int key){
        if(root==NULL)return;
        if(root->val==key){
            res=parent;
            return;
        }
        if(root->val>key)dfs(root,root->left,key);
        else dfs(root,root->right,key);
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        res=NULL;
        if(!root)return NULL; // root is NULL.
        dfs(NULL,root,key);
        if(!res && root->val!=key)return root; // key not found.
        bool isRight=true;
        TreeNode *a, *b;
        if(res==NULL){ // if root is to be deleted.
            a=root;
            b=a->left;
            while(b && b->right)b=b->right;
            if(b)b->right=a->right;
            else return a->right;
            root=a->left;
            a->left=a->right=NULL;
            delete a;
            return root;
        }
        if(res->left && res->left->val==key){
            a=res->left;
            isRight=false;
        }
        else if(res)
            a=res->right;
        b=a->left;
        if(b)
        {
            while(b->right)b=b->right;
            b->right=a->right;
            if(isRight)res->right=a->left;
            else res->left=a->left;
        }
        else
        {
            if(isRight)res->right=a->right;
            else res->left=a->right;
          
        }
        a->left=a->right=NULL;
        delete a;  
        return root;
    }
};