// 234. Palindrome Linked List
// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

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
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* temp=curr;

        while(curr){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head->next)return true;
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* newHead=reverse(slow->next);

        while(newHead){
            if(head->val!=newHead->val)return false;
            head=head->next;
            newHead=newHead->next;
        }
        return true;

    }
};
 
// class Solution {
// public:
  
//     bool isPalindrome(ListNode* head) {
//        vector<int>v;
//        ListNode* temp=head;
//        while(temp){
//         v.push_back(temp->val);
//         temp=temp->next;
//        }

//        int i=0,j=v.size()-1;
//        while(i<j){
//         if(v[i]!=v[j])return false;
//         i++;
//         j--;
//        }
//        return true;

//     }
// };