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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fptr=head;
        ListNode* sptr=head;
        do{
            if(fptr==NULL)return NULL;
            if(fptr->next==NULL)return NULL;
            fptr=fptr->next->next;
            sptr=sptr->next;
        }while(fptr!=sptr);
        while(head!=sptr){
            head=head->next;
            sptr=sptr->next;
        }
        return head;
    }
};