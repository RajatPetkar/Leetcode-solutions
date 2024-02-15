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
   ListNode* removeElements(ListNode* head, int targetValue) {
    if (head == nullptr) {
        return head;
    }

    while (head != nullptr && head->val == targetValue) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr != nullptr) {
        if (curr->val == targetValue) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}
};