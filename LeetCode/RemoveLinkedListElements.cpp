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
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val==val){
            head=head->next;
        }
        if(!head)return head;
        ListNode *iter=head->next, *prev=head;
        while(iter!=NULL){
            if(iter->val==val){
                prev->next=iter->next;
                iter=iter->next;
            }//end of if.
            else{
                prev=iter;
                iter=iter->next;
            }
        }//end of while.
        return head;
    }
};