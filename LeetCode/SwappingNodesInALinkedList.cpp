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
 // My solution
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head)return head;
        ListNode* iter=head;
        int len=0;
        while(iter){
            len++;
            iter=iter->next;
        }//end of while. 
        int f=k-1,s=len-k;
        ListNode* fN=head;
        while(f--){
            fN=fN->next;
        }
        ListNode* sN=head;
        while(s--){
            sN=sN->next;
        }
        int temp=fN->val;
        fN->val=sN->val;
        sN->val=temp;
        return head;
    }
};


// 1 pass solution ~ keeps a window of size k.
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *prev = head, *nxt = head;
        for(int i = 1; i <= k - 1; i++)
            nxt = nxt->next;
        ListNode *marker1 = nxt;
        while(nxt->next)
        {
            prev = prev->next;
            nxt = nxt->next;
        }
        swap(prev->val, marker1-> val);
        return head;
    }
};