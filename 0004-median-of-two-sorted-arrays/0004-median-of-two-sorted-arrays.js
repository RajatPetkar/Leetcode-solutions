/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    let res = [...nums1, ...nums2].sort((a, b) => a - b);
    let left = 0, right = res.length - 1;

    while (left <= right) {
        let mid = Math.floor((left + right) / 2);

        if (res[left] <= res[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    let medianIndex = Math.floor((res.length - 1) / 2);
    if (res.length % 2 === 0) {
        return (res[medianIndex] + res[medianIndex + 1]) / 2;
    } else {
        return res[medianIndex];
    }
};
