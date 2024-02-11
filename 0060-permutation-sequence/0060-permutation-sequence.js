/**
 * @param {number} n
 * @param {number} k
 * @return {string}
 */
// function solve(arr, ans, index) {
//     if (index >= arr.length) {
//         ans.push(arr);
//         return;
//     }
//     for (let j = index; j < arr.length; j++) {
//         let chars = arr.split('');
//         let temp = chars[index];
//         chars[index] = chars[j];
//         chars[j] = temp;
//         solve(chars.join(''), ans, index + 1);
//     }
// }

// var getPermutation = function(n, k) {
//     let ans = [];
//     let index = 0;
//     let str = ""
//     for(let i=1;i<=n;i++){
//         str += i;
//     }
//     solve(str, ans, index);
//     ans.sort()
//     return ans[k-1];
// };

var getPermutation = function(n, k) {
    let factorials = [1];
    for (let i = 1; i <= n; i++) {
        factorials[i] = factorials[i - 1] * i;
    }
    
    let digits = [];
    for (let i = 1; i <= n; i++) {
        digits.push(i);
    }
    
    let ans = "";
    k--; 
    for (let i = n - 1; i >= 0; i--) {
        let idx = Math.floor(k / factorials[i]);
        ans += digits[idx];
        digits.splice(idx, 1); 
        k %= factorials[i];
    }
    
    return ans;
};
