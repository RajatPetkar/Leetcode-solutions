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
     ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        int cnt = 1;

        while (cnt < left) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        ListNode* beforeReverse = prev;

        ListNode* reversedTail = curr;
        prev = NULL;
        while (cnt <= right) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }

        if (beforeReverse != NULL) {
            beforeReverse->next = prev;
        } else {
            head = prev;
        }
        reversedTail->next = curr;

        return head;
    }
};