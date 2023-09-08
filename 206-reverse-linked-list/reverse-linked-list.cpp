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
    ListNode* reverse(ListNode* &prev,ListNode* &curr){
        if(curr == NULL){
            return prev;
        }
        ListNode* forward=curr->next;
        return reverse(curr,forward);
        curr->next = prev;
    }

    ListNode* reverseList(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head; // No need to reverse if the list is empty or has only one node.
    }

    ListNode* prev = head;
    ListNode* curr = head->next;
    ListNode* forward = NULL;

    while (curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    head->next = NULL; // Set the new tail's next pointer to NULL.
    return prev; // prev is now the new head of the reversed list.
}

    
};