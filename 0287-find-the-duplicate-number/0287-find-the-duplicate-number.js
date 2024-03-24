/**
 * @param {number[]} nums
 * @return {number}
 */
function findDuplicate(nums) {
    let tortoise = nums[0];
    let hare = nums[0];
    do {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    } while (tortoise !== hare);

    let ptr1 = nums[0];
    let ptr2 = tortoise;
    while (ptr1 !== ptr2) {
        ptr1 = nums[ptr1];
        ptr2 = nums[ptr2];
    }

    return ptr1;
}