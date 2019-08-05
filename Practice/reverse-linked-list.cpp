//https://leetcode.com/problems/reverse-linked-list/



//Iterative Approach 
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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *prev=NULL, *curr=head, *next_elem=head->next;
        while(curr){
            curr->next=prev;
            prev=curr;
            curr=next_elem;
            if(next_elem) next_elem=next_elem->next;
        }
        
        return prev;
    }
};




//Recursive Approach
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
    ListNode* new_head;
    void reverse(ListNode* head){
        if(!head->next){
            new_head=head;
            return;
        }
        reverse(head->next);
        head->next->next=head;
        head->next=NULL;
    }
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        reverse(head);
        return new_head;
    }
};




//Simpler Recursive Approach

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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* new_head=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return new_head;
    }
};
