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
class Solution {
    ListNode* reverse(ListNode* head){
        ListNode *iter=head, *tmp;
        while(iter->next){
            tmp=iter->next;
            iter->next=tmp->next;
            tmp->next=head;
            head=tmp;
        }
        return head;
    }
public:
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL)return;
        ListNode* fptr=head;
        ListNode* sptr=head;
        while(sptr!=NULL){
            sptr=sptr->next;
            if(sptr==NULL || sptr->next==NULL)break;
            sptr=sptr->next;
            fptr=fptr->next;
        }//end of while.
        sptr=fptr->next;
        fptr->next=NULL;fptr=head;
        sptr=reverse(sptr);
        ListNode *iter=NULL, *tmp;
        int toggle=1;
        while(sptr || fptr){
            if(!toggle)
                tmp=sptr,sptr=sptr->next;
            else
                tmp=fptr,fptr=fptr->next;
            tmp->next=NULL;
            toggle=1-toggle;
            if(!iter)iter=tmp;
            else{
                iter->next=tmp;
                iter=iter->next;
            }
        }//end of while.
    }
};