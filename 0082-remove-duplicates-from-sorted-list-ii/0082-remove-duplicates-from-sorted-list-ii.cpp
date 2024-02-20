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
   ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* curr = head;

    while (curr != nullptr) {
        bool duplicated = false;

        while (curr->next != nullptr && curr->next->val == curr->val) {
            duplicated = true;
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }

        if (duplicated) {
            ListNode* temp = curr;
            curr = curr->next;
            delete temp;
            prev->next = curr;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return  dummy->next;
}
};
