//https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*> hmap;
        int sum=0;
        ListNode* new_head=head;
        ListNode* temp=head;
        while(temp){
            sum+=temp->val;
            if(sum==0) new_head=temp->next;
            else if(hmap.find(sum)==hmap.end()) hmap[sum]=temp;
            else hmap[sum]->next=temp->next;
            temp=temp->next;
        }
        return new_head;
        
    }
};
