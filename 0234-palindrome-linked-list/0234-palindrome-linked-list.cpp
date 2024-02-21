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
//Approach 1
//     bool Palindrome(vector<int> arr){
//         int size = arr.size();
//         int s = 0;
//         int e = size-1;
        
//         while(s<=e){
//             if(arr[s]!=arr[e]){
//                 return 0;
//             }
//             s++;
//             e--;
//         }
//         return 1;
//     }
    
    ListNode* getMid(ListNode* &head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast!=NULL && fast->next !=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode *&head){
    ListNode *prev = NULL;
    ListNode *curr = head;
    while (curr)
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
    
    bool isPalindrome(ListNode* head) {
// Approach 1
//         vector<int> arr;
//         ListNode* temp = head;
        
//         while(temp!=NULL){
//             arr.push_back(temp->val);
//             temp=temp->next;
//         }
//         return Palindrome(arr);

// Approach 2
       if(head->next == NULL){
           return true;
       } 
       ListNode* middle = getMid(head);
        ListNode* temp = middle->next;
        middle->next = reverse(temp);

        ListNode* head1 = head;
        ListNode* head2 = middle->next;
        
        while(head2!=NULL){
            if(head1->val != head2->val){
                return false;
            }
            
            head1 = head1->next;
            head2 = head2->next;
        }
        temp = middle->next;
        middle->next = reverse(temp);
        return true;
    }
};