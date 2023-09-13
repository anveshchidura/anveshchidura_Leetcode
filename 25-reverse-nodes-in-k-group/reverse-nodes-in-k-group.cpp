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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* fwd = NULL;
        int cnt = 0;
        while(curr != NULL && cnt < k){
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
            cnt++;
        }
        if (cnt < k) {
            return reverseKGroup(prev, cnt);
        }
        head -> next = reverseKGroup(fwd,k); 
        return prev;

    }
};