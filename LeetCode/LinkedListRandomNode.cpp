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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    vector<int> arr;
    int N;
    Solution(ListNode* head) {
        while(head)
        {
            arr.push_back(head->val);
            head=head->next;
        }
        N=arr.size();
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int r=rand()%N;
        return arr[r];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

~ What if the linked list is extremely large and its length is unknown to you?
~ Could you solve this efficiently without using extra space?
// Check the solution of the problem. It will answer your questions. 

Reservior Sampling. 