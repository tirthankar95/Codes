/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
const int mxSize=1e3+1;
Node pool[mxSize];
int poolPtr=0;
class Solution {
    Node *root,*iter;
    Node* getNode(int val)
    {
        Node* tmp=&pool[poolPtr];
        poolPtr=(poolPtr+1)%mxSize;
        tmp->val=val;
        tmp->prev=NULL;tmp->next=NULL;tmp->child=NULL;
        return tmp;
    }
    void trav(Node* head)
    {
        while(head!=NULL)
        {
            Node* tmp=getNode(head->val);
            if(root==NULL)
            {
                root=tmp;
                iter=tmp;
            }
            else
            {
                iter->next=tmp;
                tmp->prev=iter;
                iter=iter->next;
            }
            if(head->child)
                trav(head->child);
            head=head->next;
        }
    }
public:
    Node* flatten(Node* head) {
        if(!head)return NULL;
        root=NULL;iter=NULL;
        trav(head);
        return root;
    }
};