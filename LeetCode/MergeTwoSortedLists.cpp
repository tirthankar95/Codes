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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head=NULL,*iter=NULL;
        while(list1 && list2){
            if(list1->val<=list2->val){
                if(iter==NULL){
                    head=iter=list1;
                }
                else{
                    iter->next=list1;
                    iter=iter->next;
                }
                list1=list1->next;
            }//end of if. 
            else{
                if(iter==NULL){
                    head=iter=list2;
                }
                else{
                    iter->next=list2;
                    iter=iter->next;
                }
                list2=list2->next;
            }
        }//end of while. 
        if(list1){
            if(iter==NULL){
                head=iter=list1;
            }
            else{
                iter->next=list1;
            }
        }//
        if(list2){
            if(iter==NULL){
                head=iter=list2;
            }
            else{
                iter->next=list2;
            }
        }//
        return head;
    }//end of function. 
};