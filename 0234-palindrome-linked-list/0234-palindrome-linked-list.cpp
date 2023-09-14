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
    ListNode* middle(ListNode* head){
        if(head == NULL||head->next == NULL ){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;            
        }
        ListNode* mid = slow;
        return mid;

    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        while(curr!=NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;

        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL){
            return false;
        }
        ListNode* mid = middle(head);
        ListNode* prev = mid;
        mid->next = reverseList(mid->next);
        ListNode* newhead = mid->next;
        while(head!=NULL && newhead!=NULL){
            if(head->val != newhead->val){
                return false;                
            }
            head = head->next;
            newhead = newhead->next; 
        }
        return true;
        

    }
};