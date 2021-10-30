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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=0;
        ListNode* iter=head;
        while(iter){
            len++;
            iter=iter->next;
        }
        iter=head;
        int sLen=len/k;
        int extra=len%k;
        int i=0;vector<ListNode*> ans;
        if(len>=k){
            while(iter)
            {
                ListNode* h_=iter;
                ListNode* prev=NULL;
                i=0;
                while(i<sLen){
                    prev=iter;
                    iter=iter->next;
                    i++;
                }
                if(extra){
                    prev=iter;
                    iter=iter->next;
                    extra--;
                }
                if(prev)prev->next=NULL;
                ans.push_back(h_);
            }//end of while
        }//end of if.
        else{
            while(iter)
            {
                ListNode* h_=iter;
                ListNode* prev=iter;
                iter=iter->next;
                prev->next=NULL;
                ans.push_back(h_);
            }
            extra=k-len;
            while(extra--)
            {
                ListNode* h_=NULL;
                ans.push_back(h_);
            }
        }//end of else.
        return ans;
    }
};