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
class Solution {
    int saveElement;
    int rank(TreeNode* root,int k,int parentRank){
        if(!root)return parentRank;
        int lr=rank(root->left,k,parentRank);
        if(saveElement!=-1)return 0;
        lr++;
        if(lr==k){
            saveElement=root->val;
            //return 0;
        }
        int rr=rank(root->right,k,lr);
        if(saveElement!=-1)return 0;
        return rr;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        saveElement=-1;
        rank(root,k,0);
        return saveElement;
    }
};

/****** Iterative Solution *******/
 * class Solution {
  public int kthSmallest(TreeNode root, int k) {
    LinkedList<TreeNode> stack = new LinkedList<>();

    while (true) {
      while (root != null) {
        stack.push(root);
        root = root.left;
      }
      root = stack.pop();
      if (--k == 0) return root.val;
      root = root.right;
    }
  }
}
/******************************/