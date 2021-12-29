/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    int N;// length of the ptr vector.
    void dfs(Node* root,vector<Node*>& ptr,int ht){
        if(!root)return;
        if(N<=ht){
            ptr.push_back(root);
            N++;
        }
        else{
            ptr[ht]->next=root;
            ptr[ht]=root;
        }
        dfs(root->left,ptr,ht+1);
        dfs(root->right,ptr,ht+1);
    }
public:
    Node* connect(Node* root) {
        vector<Node*> ptr;
        N=0;
        dfs(root,ptr,0);
        return root;
    }
};