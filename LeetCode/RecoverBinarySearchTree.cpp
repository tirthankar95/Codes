//#define DBG
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
    vector<TreeNode*> arr;
    void inorder(TreeNode* root){
        if(!root)return;
        inorder(root->left);
        arr.push_back(root);
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        arr.clear();
        inorder(root);
        int n=arr.size();
        int index0=-1,index1=-1;
        for(int i=0;i<n;i++)
        {
            if( i+1<n && arr[i]->val>arr[i+1]->val )
            {
                if(index0==-1 || arr[i]->val>arr[index0]->val)
                    index0=i;
            }
            if( i-1>=0 && arr[i-1]->val>arr[i]->val )
            {
                if(index1==-1 || arr[i]->val<arr[index1]->val)
                    index1=i;
            }
#ifdef DBG
            cout<<index0<<" , "<<index1<<endl;
#endif
        }
#ifdef DBG
        cout<<index0<<" "<<index1<<endl;
#endif
        swap(arr[index0]->val,arr[index1]->val); 
    }
};