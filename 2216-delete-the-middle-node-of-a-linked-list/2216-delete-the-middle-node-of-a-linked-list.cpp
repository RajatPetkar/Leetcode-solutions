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
    
    
    // ListNode* deleteMiddle(ListNode* head) {
    //     int ans = getMid(head);
        
    //     if (head == nullptr || head->next == nullptr) {
    //   return nullptr;
    // }
        
    //     if (ans == 1)
    // {
    //     ListNode *temp = head;
    //     head = head->next;
    //     temp->next = NULL;
    //     delete temp;
    //     return head;
    // }
        
    //     ListNode *curr = head;
    //     ListNode *prev = NULL;
    //     int cnt = 1;

    //     while (cnt < ans)
    //     {
    //         prev = curr;
    //         curr = curr->next;
    //         cnt++;
    //     }
    //     prev->next = curr->next;
    //     curr->next = NULL;
    //     delete curr;
    //     return head;
    // }

    ListNode* deleteMiddle(ListNode* head) {
   
    if (!head || !head->next) {
        return nullptr;
    }

    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = nullptr;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = slow->next;

    return head;
}


};