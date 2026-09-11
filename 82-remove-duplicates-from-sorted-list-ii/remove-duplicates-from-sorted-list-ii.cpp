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
        
        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* dummy = temp;
        
        while(temp != NULL && temp->next != NULL && temp->next->next != NULL){
            if(temp->next->val == temp->next->next->val){
                int a = temp->next->val;
                ListNode* prev = temp;
                while(prev->next != NULL && prev->next->val == a ){
                    prev = prev->next;
                }
                
                temp->next = prev->next;
            }else{
                temp = temp->next;
            }
        }

        return dummy->next;
    }
};