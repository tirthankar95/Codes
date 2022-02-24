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
//#define DBG

class Solution {
#ifdef DBG
    void print(ListNode* head){
        while(head){
            cout<<head->val<<" ";
            head=head->next;
        }
        cout<<endl;
    }
#endif
    void merge_(ListNode** a0,ListNode* a2){
        ListNode *a1=*a0,*ap=NULL,*temp=NULL;
#ifdef DBG
        cout<<a1->val<<"~"<<a2->val<<endl;
#endif
        while(a1 && a2){
            if(a1->val<a2->val){
                ap=a1;
                a1=a1->next;
            }
            else {
                temp=a2;
                a2=a2->next;
                if(ap){
                    ap->next=temp;
                    ap=ap->next;
                }
                else{
                    ap=temp;
                    *a0=temp;
                }
                ap->next=a1;
            }
        }
        if(a2)
            ap->next=a2;
    }
    void mSort(ListNode** head){
        ListNode *f=*head, *s=*head, *sp;
        while(f){
            f=f->next;
            sp=s;
            s=s->next;
            if(f)
                f=f->next;
        }
        if(!s)return;
        sp->next=NULL;
        mSort(head);
        mSort(&s);
        merge_(head,s);
#ifdef DBG
        print(*head);
#endif 
    }
public:
    ListNode* sortList(ListNode* head) {
        mSort(&head);
        return head;
    }
};