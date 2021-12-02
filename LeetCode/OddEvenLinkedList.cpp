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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)return head;
        ListNode *o=head,*e=head,*tmp;
        int len=1;
        while(e->next!=NULL){
            e=e->next;
            len++;
        }
        if(len==2)return head;
        len/=2;
        while(len--){
            tmp=o->next;
            o->next=tmp->next;
            tmp->next=NULL;
            e->next=tmp;
            e=e->next;
            o=o->next;
        }
        return head;
    }
};