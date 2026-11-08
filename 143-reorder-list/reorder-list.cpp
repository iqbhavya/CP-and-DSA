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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr != nullptr){
            ListNode* dummy = curr->next;

            curr->next = prev;
            prev = curr;
            curr = dummy;
        }

        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }   

        ListNode* tempo = slow->next;
        slow->next = nullptr;

        ListNode* second = reverse(tempo);

        ListNode* dummy = head;
        ListNode* ans = head;

        while(second != nullptr && dummy != nullptr){
            ListNode* temp = dummy->next;
            ListNode* temp2 = second->next;
            dummy->next = second;
            second->next = temp;
            dummy = temp;
            second = temp2;
        }
    }
};