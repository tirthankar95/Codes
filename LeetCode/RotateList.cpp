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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return head;
        int len=0;
        ListNode* iter=head;
        while(iter){
            len++;
            iter=iter->next;
        }//end of while. 
        k=k%len;
        if(!k)return head;
        iter=head;int count=0;
        while(iter){
            count++;
            if(len-count==k)
                break;
            iter=iter->next;
        }//end of while. 
        ListNode* headtemp=iter->next;
        iter->next=NULL;
        ListNode* itertemp=headtemp;
        while(itertemp->next){
            itertemp=itertemp->next;
        }
        itertemp->next=head;
        return headtemp;
    }
};