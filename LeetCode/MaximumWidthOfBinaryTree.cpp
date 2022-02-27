typedef vector<int> vi;
typedef long long ll;
const ll MOD=(ll)INT_MAX+1;
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
    ll maxwid;
    vector<ll> lvlArr;
    int getHeight(TreeNode* root){
        if(root==NULL)return 0;
        return 1+max(getHeight(root->left),getHeight(root->right));
    }
    void dfs(TreeNode* root,int lvl,ll curr){
        if(root==NULL)return;
        dfs(root->left,lvl+1,((ll)2*curr)%MOD);
        dfs(root->right,lvl+1,((ll)2*curr+1)%MOD);
        if(lvlArr[lvl]==-1)
            lvlArr[lvl]=curr;
        ll temp=(curr-lvlArr[lvl])%MOD;
        if(temp<0)temp=(temp+MOD)%MOD;
        if(maxwid<temp){
            maxwid=temp;
        }
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ht=getHeight(root);maxwid=0;
        lvlArr.resize(ht,-1);
        dfs(root,0,0);
        return maxwid+1;
    }
};