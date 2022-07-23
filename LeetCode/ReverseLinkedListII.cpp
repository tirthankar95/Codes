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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* pp=new ListNode(INT_MAX,head);
        int i;
        for(i=1;i<left;i++)
            pp=pp->next;
        ListNode *prev=pp->next;
        ListNode *curr=prev->next;
        for(;i<right;i++)
        {
            prev->next=curr->next;
            curr->next=pp->next;
            pp->next=curr;
            curr=prev->next;
        }
        if(left==1)return pp->next;
        return head;
    }
};