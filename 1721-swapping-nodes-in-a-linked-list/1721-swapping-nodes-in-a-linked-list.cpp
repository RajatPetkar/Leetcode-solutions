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
    int getLength(ListNode *&head){
        int len = 0;
        ListNode *temp = head;
        while (temp != NULL){
            len++;
            temp = temp->next;
        }
    return len;
}

    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *temp = head;
        ListNode *temp2 = head;

        int cnt = 1;
        int lastkthelement = getLength(head)-k+1;
        
        while (cnt < k){
            temp = temp->next;
            cnt++;
        }
        cnt = 1;
        while (cnt < lastkthelement){
            temp2 = temp2->next;
            cnt++;
        }
        int next = temp2->val;
        temp2->val = temp->val;
        temp->val = next;
        return head;
    }
};