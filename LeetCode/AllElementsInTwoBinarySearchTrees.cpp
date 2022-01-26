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
const int mxSize=5e3+1;
int savArr1[mxSize];
int savArr2[mxSize];

typedef vector<int> vi;
class Solution {
    int a1,a2;
    bool opt1;
    void inorder_(TreeNode* root){
        if(!root)return;
        inorder_(root->left);
        if(opt1)
            savArr1[a1++]=root->val;
        else 
            savArr2[a2++]=root->val;
        inorder_(root->right);
    }
public:
    vi getAllElements(TreeNode* root1, TreeNode* root2) {
        a1=0,opt1=true;
        inorder_(root1);
        a2=0,opt1=false;
        inorder_(root2);
        vi sol(a1+a2);
        int iter=0,iter1=0,iter2=0;
        while(iter1<a1 && iter2<a2){
            if(savArr1[iter1]<=savArr2[iter2])
                sol[iter++]=savArr1[iter1++];
            else 
                sol[iter++]=savArr2[iter2++];
        }//end of while. 
        while(iter1<a1)
            sol[iter++]=savArr1[iter1++];
        while(iter2<a2)
            sol[iter++]=savArr2[iter2++];
        return sol;
    }
};