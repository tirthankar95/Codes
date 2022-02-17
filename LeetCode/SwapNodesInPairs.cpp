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
    ListNode* swapPairs(ListNode* head) {
        ListNode *first=head,*second,*prev=NULL;
        bool _first_=true;
        while(first)
        {
            if(first->next)
                second=first->next;
            else 
                return head;
            /* SWAP */
            first->next=second->next;
            second->next=first;
            if(prev)
                prev->next=second;
            if(_first_){
                head=second;
                _first_=false;
            }
            /********/
            prev=first;
            first=first->next;
        }//end of while.
        return head;
    }
};