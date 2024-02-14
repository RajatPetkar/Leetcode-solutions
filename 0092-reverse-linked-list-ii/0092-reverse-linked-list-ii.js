/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} left
 * @param {number} right
 * @return {ListNode}
 */
var reverseBetween = function(head, left, right) {
    let prev = null;
    let curr = head;
    let cnt = 1;

    while (cnt < left) {
        prev = curr;
        curr = curr.next;
        cnt++;
    }

    let beforeReverse = prev;

    let reversedTail = curr;
    prev = null;
    while (cnt <= right) {
        let next = curr.next;
        curr.next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    if (beforeReverse !== null) {
        beforeReverse.next = prev;
    } else {
        head = prev;
    }
    reversedTail.next = curr;

    return head;
};
