
/*
    Time Complexity: N*K
    N = Number of linked lists.
    K = Total number of elements.( N * avg number of elements in a linked list )
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
const int mxSize=1e4+1;
// ListNode pool[mxSize];
// int poolPtr=0;
class Solution {
    ListNode* setNode(int val){
        // ListNode* temp=&pool[poolPtr];
        // poolPtr=(poolPtr+1)%mxSize;
        ListNode* temp=new ListNode;
        temp->val=val;
        temp->next=NULL;
        return temp;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *root=NULL,*iter_;
        int n=lists.size(),mi,sIndex;
        vector<ListNode*> iter(n,NULL);
        for(int i=0;i<n;i++)
            iter[i]=lists[i];
        do
        {
            mi=INT_MAX;
            sIndex=-1;
            for(int i=0;i<n;i++){
                if(iter[i] && mi>iter[i]->val){
                    mi=iter[i]->val;
                    sIndex=i;
                }
            }//end of for.
            if(sIndex==-1)break;
            if(root==NULL){
                root=setNode(iter[sIndex]->val);
                iter_=root;
            }
            else{
                iter_->next=setNode(iter[sIndex]->val);
                iter_=iter_->next;
            }
            iter[sIndex]=iter[sIndex]->next;
        }while(true);
        return root;
    }
};
////////////////////////////////////////////////////////////////////////////////

/*
    Time Complexity: K * log N
    N = Number of linked lists.
    K = Total number of elements.( N * avg number of elements in a linked list )
    In each merge sorting step we have time complexity K.
    We have log N steps.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* l1,ListNode* l2){
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        ListNode* head=NULL;
        ListNode* l3;
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                ListNode *tmp=new ListNode(l1->val);
                l1=l1->next;
                if(head==NULL){head=tmp;l3=tmp;}
                else{head->next=tmp;
                    head=head->next;
                    }
            }
            else{
                ListNode *tmp=new ListNode(l2->val);
                l2=l2->next;
                if(head==NULL){head=tmp;l3=tmp;}
                else{head->next=tmp;
                    head=head->next;
                    }
            }//......
        }//.....while
        while(l1!=NULL){
            ListNode *tmp=new ListNode(l1->val);
            head->next=tmp;
            head=head->next;
            l1=l1->next;
        }
        while(l2!=NULL){
            ListNode *tmp=new ListNode(l2->val);
            head->next=tmp;
            head=head->next;
            l2=l2->next;
        }
        return l3;
    }
    ListNode* mergeKList(vector<ListNode*> &lists,int lb,int ub){
        if(lb==ub)return lists[ub];
        ListNode* l3=NULL;
        if(lb<ub){
            int mid=(ub+lb)/2;
            ListNode* l1=mergeKList(lists,lb,mid);
            ListNode* l2=mergeKList(lists,mid+1,ub);
            l3=merge(l1,l2);
        }    
        return l3;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len=lists.size();
        return mergeKList(lists,0,len-1);
    }
};