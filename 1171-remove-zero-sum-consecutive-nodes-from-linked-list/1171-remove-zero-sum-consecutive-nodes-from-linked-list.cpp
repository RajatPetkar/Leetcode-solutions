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
    ListNode* removeZeroSumSublists(ListNode* head) {
    unordered_map<int, ListNode*> prefixSums;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* current = dummy;
    int prefixSum = 0;

    while (current) {
        prefixSum += current->val;
        if (prefixSums.find(prefixSum) != prefixSums.end()) {
            current = prefixSums[prefixSum]->next;
            int tempSum = prefixSum + current->val;
            while (tempSum != prefixSum) {
                prefixSums.erase(tempSum);
                current = current->next;
                tempSum += current->val;
            }
            prefixSums[prefixSum]->next = current->next;
        } else {
            prefixSums[prefixSum] = current;
        }
        current = current->next;
    }

    return dummy->next;

    }
};