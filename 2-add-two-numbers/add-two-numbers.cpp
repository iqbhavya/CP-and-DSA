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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyhead = new ListNode(0);
        ListNode* l3 = dummyhead;
        
        int carry = 0;

        while(l1 != NULL || l2 != NULL){
            int val1 = (l1 != NULL) ? l1->val : 0;
            int val2 = (l2 != NULL) ? l2->val : 0;

            int currsum = val1 + val2 + carry;

            carry = currsum/10;
            int lastdigit = currsum % 10;

            ListNode* new_node = new ListNode(lastdigit);
            l3->next = new_node;

            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
            l3 = l3->next;
        }
        if(carry > 0){
            ListNode* new_node = new ListNode(carry);
            l3->next = new_node;
            l3 = l3->next;
        }

        return dummyhead->next;



    }
};