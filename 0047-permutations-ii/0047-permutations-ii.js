/**
 * @param {number[]} nums
 * @return {number[][]}
 */
function solve(arr, ans, index) {
    if (index >= arr.length) {
        ans.push(arr.slice());
        return;
    }
    let visited = new Set(); 
    for (let j = index; j < arr.length; j++) {
        if (!visited.has(arr[j])) {
            visited.add(arr[j]);
            let temp = arr[index];
            arr[index] = arr[j];
            arr[j] = temp;
            solve(arr, ans, index + 1);
            temp = arr[index];
            arr[index] = arr[j];
            arr[j] = temp; 
        }
    }
}

var permuteUnique = function(nums) {
    let ans = [];
    let index = 0;
    solve(nums, ans, index);
    return ans
};

