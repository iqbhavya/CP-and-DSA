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
        

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = head;
        int size = 0;
        while(temp != NULL) {
            temp = temp->next;
            size++;
        }

        ListNode* dum = dummy;

        for(int i = 0; i < size-n; i++){
            dum = dum->next;
        }

        dum->next = dum->next->next;


        return dummy->next;
    }
};