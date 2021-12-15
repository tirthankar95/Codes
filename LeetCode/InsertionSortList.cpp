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
    ListNode* insert(ListNode* head,ListNode* last_,ListNode* element){
        if(head->val>=element->val){
            element->next=head;
            return element;
        }
        ListNode *iter=head->next,*prev=head;
        while(prev!=last_){
            if(iter->val>element->val){
                prev->next=element;
                element->next=iter;
                break;
            }
            else{
                prev=prev->next;
                iter=iter->next;
            }
        }//end of while.
        return head;
    }
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || head->next==NULL)return head;
        ListNode *last_=head,*element=head->next;
        while(element!=NULL){
            if(last_->val<=element->val)
                last_=last_->next;
            else{
                last_->next=element->next;
                element->next=NULL;
                head=insert(head,last_,element);
            }
            element=last_->next;
        }//end of outer-while. 
        return head;
    }
};
