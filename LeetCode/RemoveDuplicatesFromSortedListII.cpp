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
const int markForDelete=-101;
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)return head;
        ListNode* iter=head;
        ListNode *prev=NULL, *startDelete=NULL, *temp;
        while(iter!=NULL)
        {
            if(iter->next && iter->val==iter->next->val){
                while(iter->next && iter->val==iter->next->val){
                    temp=iter;
                    iter=iter->next;
                    temp->next=NULL;
                    delete temp;
                }
                temp=iter;
                iter=iter->next;
                temp->next=NULL;
                delete temp;
                if(prev)prev->next=iter;
            }
            else
            {
                if(!prev)head=prev=iter;
                else prev=prev->next;
                iter=iter->next;
            }
        }//end of while.
        return (prev)?head:NULL;
    }
};