//https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(0);
        ListNode* temp=head;
        int s=0,c=0;
        s=(l1->val+l2->val+c)%10;
        c=(l1->val+l2->val+c)/10;
        l1=l1->next;
        l2=l2->next;
        temp->val=s;
        
        while(l1 || l2){
            if(l1 && l2){
                s=(l1->val+l2->val+c)%10;
                c=(l1->val+l2->val+c)/10;
                l1=l1->next;
                l2=l2->next;
            }
            else if(l1){
                 s=(l1->val+c)%10;
                 c=(l1->val+c)/10;
                 l1=l1->next;
            }
            
            else if(l2){
                 s=(l2->val+c)%10;
                 c=(l2->val+c)/10;
                l2=l2->next;
            }
            ListNode* temp2=new ListNode(s);
            temp->next=temp2;
            temp=temp->next;
        }
        
        if(c){
            ListNode* temp3=new ListNode(c);
            temp->next=temp3; 
        }
        return head;
    }
};
