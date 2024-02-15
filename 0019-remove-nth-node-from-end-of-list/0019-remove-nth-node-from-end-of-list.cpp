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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || n <= 0) {
            return nullptr; 
        }

        if (n == 1 && head->next == nullptr) {
            delete head;
            return nullptr;
        }

        int len = getLen(head);
        ListNode* curr = head;
        ListNode* prev = nullptr;

        for (int i = 0; i < len - n; ++i) {
            prev = curr;
            curr = curr->next;
        }

        // Remove the node
        if (prev) {
            prev->next = curr->next;
        } else {
            head = curr->next;
        }
        delete curr;

        return head;
    }

private:
    int getLen(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }
        return len;
    }
};
