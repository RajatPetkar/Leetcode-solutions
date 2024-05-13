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
    ListNode* mergeNodes(ListNode* head) {
        int sum=0;
        ListNode*temp=head;
        ListNode*moving=temp->next;
        while(moving!=NULL){
            if(moving->val==0){
                temp->next=moving;
                moving->val=sum;
                sum=0;
                temp=moving;
            }
            else{
            sum+=moving->val;
            }
            moving=moving->next;

        }
        return head->next;
    }
};