/**
 * @param {string} digits
 * @return {string[]}
 */
const digitToCharsMap = {
    '2': 'abc',
    '3': 'def',
    '4': 'ghi',
    '5': 'jkl',
    '6': 'mno',
    '7': 'pqrs',
    '8': 'tuv',
    '9': 'wxyz'
};

var letterCombinations = function(digits) {
    let ans = [];
    solve(digits, '', 0, ans);
    return ans;
};


function solve(digits, output, index, ans) {
    if (index === digits.length) {
        if(output.length > 0)
            ans.push(output);
        return;
    }
    const currentChars = digitToCharsMap[digits[index]];
    for (let char of currentChars) {
        solve(digits, output + char, index + 1, ans);
    }
}