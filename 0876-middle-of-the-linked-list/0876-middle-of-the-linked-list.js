/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
function getMid(head){
        let len = 0;
        let temp = head;
        while (temp != null)
        {
            len++;
            temp = temp.next;
        }
        return Math.floor((len/2)+1);
    }

var middleNode = function(head) {
    let ans = getMid(head);
        let cnt = 1;
        
        let curr = head;
        while (cnt < ans)
        {
            curr = curr.next;
            cnt++;
        }
        return curr;
};