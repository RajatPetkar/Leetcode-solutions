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

class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        int k = lists.size();
        
        if (k == 0) {
            return nullptr;
        }
        for (int i = 0; i < k; i++) {
            if (lists[i] != nullptr) {
                minHeap.push(lists[i]);
            }
        }
        
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while (!minHeap.empty()) {
            ListNode* temp = minHeap.top();
            minHeap.pop();
            
            if (head == nullptr) {
                head = temp;
                tail = temp;
                if (tail->next != nullptr) {
                    minHeap.push(tail->next);
                }
            } else {
                tail->next = temp;
                tail = temp;
                if (tail->next != nullptr) {
                    minHeap.push(tail->next);
                }
            } 
        }
        return head;        
    }
};
