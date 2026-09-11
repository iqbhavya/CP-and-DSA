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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;
        

        while(dummy != NULL && dummy->next != NULL && dummy->next->next != NULL){
            if(dummy->next->val == dummy->next->next->val){
                
                
                dummy->next = dummy->next->next;
            }else{
                dummy = dummy->next;
            }

            
        }
        
        return temp->next;

    }
};