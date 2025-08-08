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
    // int getMid(ListNode *&head){
    //     int len = 0;
    //     ListNode *temp = head;
    //     while (temp != NULL)
    //     {
    //         len++;
    //         temp = temp->next;
    //     }
    //     return (len/2)+1;
    // }
    // ListNode* middleNode(ListNode* head) {
    //     int ans = getMid(head);
    //     int cnt = 1;

    //     ListNode *curr = head;
    //     while (cnt < ans)
    //     {
    //         curr = curr->next;
    //         cnt++;
    //     }
    //     return curr;
    // }

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};