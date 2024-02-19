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
    bool hasCycle(ListNode *head) {
    if (!head || !head->next)
        return false;

    ListNode *pre = head;
    ListNode *cur = head->next;

    while (pre != cur) {
        if (!cur || !cur->next)
            return false;
        pre = pre->next;
        cur = cur->next->next;
    }

    return true;
}
};