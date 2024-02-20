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
    
    ListNode* solve(ListNode* &list1, ListNode* &list2){
        ListNode* curr = list1;
        ListNode* next = curr->next;
        ListNode* curr1 = list2;
        ListNode* next1 = curr1->next;

        if(list1->next==NULL){
            list1->next = list2;
            return list1;
        }
        
        while(next!=NULL && curr1!=NULL){
            if((curr1->val >=curr->val)&&(curr1->val <=next->val)){
                curr->next = curr1;
                next1 = curr1->next;
                curr1->next = next;
                curr= curr1;
                curr1=next1;
            }else{
                curr = next;
                next = next->next;
                
                if(next==NULL){
                    curr->next = curr1;
                    return list1;
                }
            }
        }
        return list1;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        if(list1->val <= list2->val){
           return solve(list1,list2);
        }else{
           return solve(list2,list1);
        }
        return list1;
    }
};