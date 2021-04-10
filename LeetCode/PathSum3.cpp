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
    int gCnt;
    int SUM;
    void dfs(TreeNode* root,vector<int>& sum)
    {
        if(root==NULL)return;
        sum.push_back(root->val);
        int rSum=0;
        for(int i=sum.size()-1;i>=0;i--)
        {
            rSum+=sum[i];
            if(rSum==SUM)gCnt++;
        }
        dfs(root->left,sum);
        dfs(root->right,sum);     
        sum.erase(sum.begin()+(sum.size()-1));
    }
public:
    int pathSum(TreeNode* root, int sum) {
        gCnt=0;SUM=sum;
        vector<int> tmp;
        dfs(root,tmp);
        return gCnt;
    }
};
/////////////////////// Better Solution /////////////////////////////////
 int pathSum(TreeNode* root, int sum) {
    unordered_map<int, int> m;
    m[0] = 1;
    int count = 0;
    pathSumRecur(root, sum, 0, count, m);
    return count;
}

void pathSumRecur(TreeNode* root, int sum, int curSum, int& count, unordered_map<int, int>& m){
    if(!root)
        return;
    curSum += root->val;
    if(m.find(curSum-sum) != m.end()){
        count += m[curSum-sum];
    }
    m[curSum]++;
    pathSumRecur(root->left, sum, curSum, count, m);
    pathSumRecur(root->right, sum, curSum, count, m);
    m[curSum]--;
}