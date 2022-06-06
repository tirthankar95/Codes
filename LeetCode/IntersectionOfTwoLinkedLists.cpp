/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//#define SOL1
class Solution {
#ifdef SOL1
    int len(ListNode* head){
        int count=0;
        while(head){
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode* fn(ListNode* headA,ListNode* headB){
        int len1=len(headA);
        int len2=len(headB);
        ListNode *ptr1,*ptr2;
        if(len1>=len2){
            ptr1=headA;
            ptr2=headB;
        }
        else{
            ptr1=headB;
            ptr2=headA;
        }
        int d=abs(len1-len2);
        while(d){
            ptr1=ptr1->next;
            d--;
        }
        while(ptr1 && ptr2){
            if(ptr1==ptr2)
                return ptr1;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return NULL;
    }
#else
    ListNode* fn1(ListNode* headA,ListNode* headB){
        ListNode* iter=headA;
        if(headA==NULL || headB==NULL)return NULL;
        while(iter->next){
            iter=iter->next;
        }
        iter->next=headB;
        ListNode* fptr=headA;
        ListNode* sptr=headA;
        while(fptr){
            fptr=fptr->next;
            if(!fptr){
                iter->next=NULL;
                return NULL;
            }
            fptr=fptr->next;
            sptr=sptr->next;
            if(fptr==sptr)
                break;
        }//end of while.
        if(fptr!=sptr){
            iter->next=NULL;
            return NULL;            
        }
        fptr=headA;
        while(fptr!=sptr){
            fptr=fptr->next;
            sptr=sptr->next;
        }
        iter->next=NULL;
        return fptr;
    }
#endif
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
#ifdef SOL1 
        return fn(headA,headB);
#else
        return fn1(headA,headB);
#endif
    }
};