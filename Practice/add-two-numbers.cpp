//https://leetcode.com/problems/add-two-numbers/




class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry=0) {
        if(l1==NULL && l2==NULL && carry==0) return NULL;
        if(l1==NULL && l2==NULL && carry!=0) return new ListNode(carry);
        if(l1!=NULL && l2==NULL){
            ListNode* temp=new ListNode((l1->val+carry)%10);
            temp->next=addTwoNumbers(l1->next,l2,(l1->val+carry)/10);
            return temp;
        }
        if(l1==NULL && l1==NULL){
            ListNode* temp=new ListNode((l2->val+carry)%10);
            temp->next=addTwoNumbers(l1,l2->next,(l2->val+carry)/10);
            return temp;
        }
        ListNode* temp=new ListNode((l1->val+l2->val+carry)%10);
        temp->next=addTwoNumbers(l1->next,l2->next,(l1->val+l2->val+carry)/10);
        return temp;
        
    }
};
