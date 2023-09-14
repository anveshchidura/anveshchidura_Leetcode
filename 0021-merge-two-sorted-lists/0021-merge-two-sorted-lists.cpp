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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }     
        if(list1->val>list2->val){
            std::swap(list1,list2);
        }
        ListNode* res = list1;
        while(list1!=NULL && list2!=NULL){
            ListNode* temp = NULL;
            while(list1!=NULL && list1->val<=list2->val){
                temp = list1;
                list1 = list1->next;
            }
            temp->next = list2;
            std::swap(list1,list2);    
        }
        return res;
        /*
        ListNode* left = list1;
        ListNode* right = list2;
        ListNode* temp1 = NULL;
        ListNode* temp = NULL;
        if(left== NULL && right == NULL){
            return NULL;
        }
        if(left == NULL && right != NULL){
            return right;
        }
        if(left != NULL && right == NULL){
            return left;
        }
        else{
        if(left->val <= right->val){
            temp1 = left;
        }
        else{temp1 = right;}        
        while(left!=NULL && right!=NULL){
        if(left->val <= right->val){
            temp = left->next;
            left->next = right;
            left = temp;
        }
        else{
            temp = right->next;
            right->next = left;
            right = temp;
        }
        }
        return temp1;
        }
        */
    }
};