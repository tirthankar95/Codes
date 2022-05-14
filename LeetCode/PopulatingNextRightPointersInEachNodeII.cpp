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
    int getHeight(Node* root){
        if(root==NULL)return 0;
        return 1+max(getHeight(root->left),getHeight(root->right));
    }
    void dfs(Node* root,vector<Node*>& st,int ht){
        if(root==NULL)return;
        if(st[ht]==NULL)
            st[ht]=root;
        else{
            st[ht]->next=root;
            st[ht]=st[ht]->next;
        }
        dfs(root->left,st,ht+1);
        dfs(root->right,st,ht+1);
    }
public:
    Node* connect(Node* root) {
        if(root==NULL)return root;
        int ht=getHeight(root);
        vector<Node*> st(ht,NULL);
        dfs(root,st,0);
        for(int i=0;i<ht;i++){
            if(st[i])st[i]->next=NULL;
        }
        return root;
    }
};