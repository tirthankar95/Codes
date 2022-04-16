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
struct spcTreeNode{
    TreeNode* node;
    int valueFromChild;
    spcTreeNode(TreeNode* a,int b){
        node=a;
        valueFromChild=b;
    }
};
class Solution {
    spcTreeNode* convertBST_(TreeNode* root,int parentR){
        if(!root)
            return new spcTreeNode(NULL,0);
        TreeNode* temp=new TreeNode(root->val+parentR);
        int valueFromChild=root->val;
        spcTreeNode* R=convertBST_(root->right,parentR);
        temp->right=R->node;
        temp->val+=R->valueFromChild;
        spcTreeNode* L=convertBST_(root->left,temp->val);
        temp->left=L->node;
        valueFromChild+=R->valueFromChild+L->valueFromChild;
        return new spcTreeNode(temp,valueFromChild);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        return convertBST_(root,0)->node;
    }
};