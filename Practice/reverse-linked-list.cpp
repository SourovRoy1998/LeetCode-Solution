//https://leetcode.com/problems/reverse-linked-list/

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
