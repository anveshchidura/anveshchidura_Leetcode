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
        if (!head || !head->next || k == 0) {
            return head;
        }
        
        ListNode* curr = head;
        int len = 1;
        
        while (curr->next != NULL) {
            len++;
            curr = curr->next;
        }
        
        curr->next = head; // Connect the last node to the head to make it a circular list
        
        k = k % len; // Calculate effective rotations
        
        k = len - k; // Calculate the new position to break the circular list
        
        while (k > 0) {
            curr = curr->next;
            k--;
        }
        
        head = curr->next; // Update the new head
        curr->next = NULL; // Break the circular list
        
        return head;
    }
};
