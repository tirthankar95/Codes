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
    void print(ListNode* l1)
    {
        while(l1!=NULL)
        {
            cout<<l1->val<<" ";
            l1=l1->next;
        }
        cout<<endl;
    }
    ListNode* reverse(ListNode* l1)
    {
        ListNode *head=l1,*curr=l1->next,*prev=l1;
        while(curr!=NULL)
        {
            prev->next=curr->next;
            curr->next=head;
            head=curr;
            curr=prev->next;
        }
        return head;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        ListNode *head=NULL,*iter=NULL;
        int carry=0,sum=0,tmp;
        while(l1 && l2)
        {
            tmp=(l1->val+l2->val+carry);
            sum=tmp%10;
            carry=tmp/10;
            if(head==NULL)
            {
                head=new ListNode(sum);
                iter=head;
            }
            else
            {
                iter->next=new ListNode(sum);
                iter=iter->next;
            }
            l1=l1->next;
            l2=l2->next;
        }
        while(l1)
        {
            tmp=(l1->val+carry);
            sum=tmp%10;
            carry=tmp/10;  
            iter->next=new ListNode(sum);
            iter=iter->next;            
            l1=l1->next;            
        }
        while(l2)
        {
            tmp=(l2->val+carry);
            sum=tmp%10;
            carry=tmp/10;   
            iter->next=new ListNode(sum);
            iter=iter->next;            
            l2=l2->next;           
        }
        if(carry)iter->next=new ListNode(carry);
        head=reverse(head);
        return head;
    }
};