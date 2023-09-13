/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curra = headA;
        ListNode *currb = headB;
        while(curra!=currb){
            if(curra == NULL){
                curra = headB;
            }
            else{curra = curra->next;}
            if(currb == NULL){
                currb = headA;
            }           
            else{currb = currb->next;}
        }
        
        return curra;
        
        /*
        unordered_set<ListNode*> smap;
        ListNode *curra = headA;
        ListNode *currb = headB;
        while(curra!=NULL){
            smap.insert(curra);
            curra = curra->next;          
        }
        while(currb!=NULL){
            if(smap.find(currb) != smap.end()){
                return currb;
            }
            currb = currb->next;          
        }
        return NULL;
        */
        
    }
};