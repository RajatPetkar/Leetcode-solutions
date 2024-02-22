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
   ListNode* insertionSortList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    ListNode* sortedHead = nullptr; 
    ListNode* current = head;

    while (current != nullptr) {
        ListNode* nextNode = current->next;
        if (!sortedHead || current->val < sortedHead->val) {
            current->next = sortedHead;
            sortedHead = current;
        } else {
            ListNode* temp = sortedHead;
            while (temp->next != nullptr && temp->next->val < current->val) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = nextNode;
    }

    return sortedHead;
}
};