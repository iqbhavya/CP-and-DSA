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
        int l1 = 0;
        int l2 = 0;
        ListNode* dummy1 = headA;
        ListNode* dummy2 = headB;

        while(dummy1 != nullptr){
            dummy1 = dummy1->next;
            l1++;
        }

        while(dummy2 != nullptr){
            dummy2 = dummy2->next;
            l2++;
        }
        

        if(l1> l2){
            ListNode* temp = headA;
            for(int i =0; i < l1-l2; i++){
                temp = temp->next;
            }
            ListNode* temp2 = headB;

            while(temp != temp2 ){
                temp = temp->next;
                temp2 = temp2->next;
            }

            if(temp == temp2){
                return temp;
            }
        }else{
            ListNode* temp = headA;
            
            ListNode* temp2 = headB;
            for(int i =0; i < l2-l1; i++){
                temp2 = temp2->next;
            }

            while(temp != temp2 ){
                temp = temp->next;
                temp2 = temp2->next;
            }

            if(temp == temp2){
                return temp;
            }
        }

        return NULL;
    }
};