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
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fptr=head, *sptr=head;
        while(sptr){
            sptr=sptr->next;
            if(!sptr)break;
            sptr=sptr->next;
            fptr=fptr->next;
        }
        return fptr;
    }
};