//https://leetcode.com/problems/merge-k-sorted-lists/

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
    ListNode* merge(ListNode* l1, ListNode* l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val<l2->val){l1->next=merge(l1->next,l2); return l1;}
        l2->next=merge(l2->next,l1);
        return l2;
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        vector<ListNode*> arr;
        
        while(lists.size()>1){
            arr={};
            for(int i=0;i<lists.size()-1;i+=2)
                arr.push_back(merge(lists[i],lists[i+1]));
            if(lists.size()%2) arr.push_back(lists.back());
            lists=arr;
        }
        return lists[0];
    }
};
