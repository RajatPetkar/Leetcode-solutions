/**
 * @param {number[]} nums
 * @return {number[][]}
 */
function solve(arr, ans, index) {
    if (index >= arr.length) {
        ans.push(arr.slice());
        return;
    }
    for (let j = index; j < arr.length; j++) {
        let temp = arr[index];
        arr[index] = arr[j];
        arr[j] = temp;
        solve(arr, ans, index + 1);
        temp = arr[index];
        arr[index] = arr[j];
        arr[j] = temp;
    }
}

var permute = function(nums) {
     let ans = [];
    let index = 0;
    solve(nums,ans,index)
    return ans;
};

