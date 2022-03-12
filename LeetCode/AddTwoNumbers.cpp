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
/*const int mxSize=200;
ListNode pool[mxSize];
int poolCount=0;*/

ListNode* createNode(int no){
    /*ListNode* temp=&pool[poolCount];
    poolCount=(poolCount+1)%mxSize;*/
    ListNode* temp=new ListNode;
    temp->val=no;
    temp->next=NULL;
    return temp;
}
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=NULL,*prev=NULL;
        int no=0,carry=0;
        while(l1 && l2)
        {
            no=(l1->val+l2->val+carry);
            if(prev==NULL)
                head=prev=createNode(no%10);
            else{
                prev->next=createNode(no%10);
                prev=prev->next;
            }
            carry=no/10;
            l1=l1->next;l2=l2->next;
        }//end of while. (l1+l2)
        while(l1){
            no=(l1->val+carry);
            if(prev==NULL)
                head=prev=createNode(no%10);
            else{
                prev->next=createNode(no%10);
                prev=prev->next;
            }
            carry=no/10;
            l1=l1->next;           
        }// l1
        while(l2){
            no=(l2->val+carry);
            if(prev==NULL)
                head=prev=createNode(no%10);
            else{
                prev->next=createNode(no%10);
                prev=prev->next;
            }
            carry=no/10;
            l2=l2->next;          
        }//l2
        if(carry)
            prev->next=createNode(carry);
        return head;
    }
};