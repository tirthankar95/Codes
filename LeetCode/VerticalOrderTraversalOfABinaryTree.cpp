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
    unordered_map<int,vector<ii>> hMap;
    int min_,max_;
    void fn(TreeNode* root,int id,int lvl){
        if(root==NULL)return;
        min_=min(min_,id);
        max_=max(max_,id);
        hMap[id].push_back(ii(lvl,root->val));
        fn(root->left,id-1,lvl+1);
        fn(root->right,id+1,lvl+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        min_=INT_MAX;max_=INT_MIN;
        hMap.clear();
        fn(root,0,0);
        int n=max_-min_+1;
        vector<vector<int>> sol(n);
        for(int i=min_;i<=max_;i++)
        {
            sort(hMap[i].begin(),hMap[i].end());
            for(int j=0;j<hMap[i].size();j++)
                sol[i-min_].push_back(hMap[i][j].second);
        }
        return sol;
    }
};