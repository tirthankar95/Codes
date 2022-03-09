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
    bool hasCycle(ListNode *head) {
        ListNode* fptr=head;
        ListNode* sptr=head;//slow pointer. 
        while(fptr!=NULL){
            fptr=fptr->next;
            if(fptr)
                fptr=fptr->next;
            else 
                return false;
            sptr=sptr->next;
            if(sptr==fptr)
                return true;
        }
        return false;
    }
};