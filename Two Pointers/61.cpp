// 61. Rotate List
// Given the head of a linked list, rotate the list to the right by k places.

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
private:
    void solve(ListNode* &head){
       ListNode* prev=NULL;
       ListNode* curr=head;
       while(curr->next!=NULL){
           prev=curr;
           curr=curr->next;
       }
       curr->next=head;
       head=curr;;
       prev->next=NULL;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || !head )return head;
        if(!head->next)return head;
        ListNode* temp=head;
        int size=0;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        k%=size;
        while(k>0){
            solve(head);
            k--;
        }
        return head;
    }
};