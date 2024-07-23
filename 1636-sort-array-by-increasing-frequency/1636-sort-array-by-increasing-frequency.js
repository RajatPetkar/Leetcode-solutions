/**
 * @param {number[]} nums
 * @return {number[]}
 */
var frequencySort = function (nums) {
    let map = new Map()
    
    for (let num of nums) {
        map.set(num, (map.get(num) || 0) + 1)
    }

    return nums.sort((a,b)=>map.get(a)-map.get(b) || b-a)
};