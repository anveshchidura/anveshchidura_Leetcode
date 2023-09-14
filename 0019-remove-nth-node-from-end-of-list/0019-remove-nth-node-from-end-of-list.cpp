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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      if(head==NULL||head->next==NULL){return NULL;}  
      ListNode* temp = head;
      int cnt = 0;
      while(temp!=NULL){
          cnt++;
          temp=temp->next;          
      }  
      ListNode* prev = NULL;
      temp = head;    
        // Special case: removing the head node
      if (cnt - n + 1 == 1) {
            head = head->next;
            delete temp;
            return head;
        }  
      int pos  = 1;
      while(pos < (cnt-n+1) && temp!=NULL){
          prev = temp;
          temp=temp->next;   
          pos++;
      }  
      prev->next = temp->next;
      delete temp;  
      return head;  
    }
};