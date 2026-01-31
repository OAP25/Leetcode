// 2. Add Two Numbers
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

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
        int carry = 0;
        
        // Initialize dummy node to start the result list
        ListNode* ans = new ListNode(0);
        ListNode* ans1 = ans;  // Pointer to build the result list
        
        // Traverse both linked lists
        while (l1 != NULL || l2 != NULL) {
            int sum = carry;
            
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            // Compute the digit to add and the carry
            int digit = sum % 10;
            carry = sum / 10;
            
            // Create a new node for the current digit
            ListNode* temp = new ListNode(digit);
            ans1->next = temp;
            ans1 = temp;  // Move to the next position in the result list
        }
        
        // If there is still a carry left, add a new node for it
        if (carry != 0) {
            ans1->next = new ListNode(carry);
        }
        
        // Return the result, skipping the dummy node
        return ans->next;
    }
};