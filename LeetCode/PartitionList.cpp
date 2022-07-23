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
    ListNode* partition(ListNode* head, int x) {
        ListNode *p1,*p2,*c2;
        ListNode* temp=new ListNode(INT_MIN);temp->next=head;
        p1=p2=temp;
        while(p2->next)
        {
            if(p2->next->val>=x)
                p2=p2->next;
            else if(p1==p2){
                p1=p1->next;
                p2=p2->next;
            }
            else{
                c2=p2->next;
                p2->next=c2->next;
                c2->next=p1->next;
                p1->next=c2;
                p1=p1->next;
            }
        }//end-while.
        ListNode* res=temp->next;
        temp->next=NULL;
        delete temp;
        return res;
    }
};