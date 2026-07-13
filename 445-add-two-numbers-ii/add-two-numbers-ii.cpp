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
        stack<int> a , b;

        while(l1 != NULL){
            a.push(l1->val);
            l1 = l1->next;
        }

        while(l2 != NULL){
            b.push(l2->val);
            l2 = l2->next;
        }

        int sum = 0;
        int carry = 0;
        ListNode* ans = new ListNode();

        while(a.empty() == false || b.empty() == false){
            if(a.empty() == false){
                sum = sum + a.top();
                a.pop();
            }

            if(b.empty() == false){
                sum = sum + b.top();
                b.pop();
            }

            ans->val = sum%10 ;
            carry = sum/10;
            ListNode* new_node = new ListNode(carry);
            new_node->next = ans;
            ans = new_node;
            sum = carry;
        }

        if(carry == 0){
            return ans->next;
        }else{
            return ans;
        }
    }
};