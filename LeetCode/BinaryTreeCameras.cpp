/* https://leetcode.com/problems/binary-tree-cameras/solution/ */
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
 /*
 Approach 1: Dynamic Programming
Intuition

Let's try to cover every node, starting from the top of the tree and working down. Every node considered must be covered by a camera at that node or some neighbor.

Because cameras only care about local state, we can hope to leverage this fact for an efficient solution. Specifically, when deciding to place a camera at a node, we might have placed cameras to cover some subset of this node, its left child, and its right child already.

Algorithm

Let solve(node) be some information about how many cameras it takes to cover the subtree at this node in various states. There are essentially 3 states:

[State 0] Strict subtree: All the nodes below this node are covered, but not this node.
[State 1] Normal subtree: All the nodes below and including this node are covered, but there is no camera here.
[State 2] Placed camera: All the nodes below and including this node are covered, and there is a camera here (which may cover nodes above this node).
Once we frame the problem in this way, the answer falls out:

To cover a strict subtree, the children of this node must be in state 1.
To cover a normal subtree without placing a camera here, the children of this node must be in states 1 or 2, and at least one of those children must be in state 2.
To cover the subtree when placing a camera here, the children can be in any state.
*/
typedef vector<int> vi;
const int inf=1e9+1;
class Solution {
    vi fn(TreeNode* root){
        if(root==NULL){
            return vi({0,0,inf});
        }
        vi temp0=fn(root->left);
        vi temp1=fn(root->right);
        int min_l=min(temp0[1],temp0[2]);
        int min_r=min(temp1[1],temp1[2]);
        vi sol(3);
        sol[0]=temp0[1]+temp1[1];
        sol[1]=min((temp0[2]+min_r),(temp1[2]+min_l));
        sol[2]=1+min(temp0[0],min_l)+min(temp1[0],min_r);
        return sol;
    }
public:
    int minCameraCover(TreeNode* root) {
        vi temp=fn(root);
        return min(temp[1],temp[2]);
    }
};