/**
 * @param {number[]} mapping
 * @param {number[]} nums
 * @return {number[]}
 */
var sortJumbled = function(mapping, nums) {
    const translate = (num) => {
        let digits = num.toString().split('');
        for (let i = 0; i < digits.length; i++) {
            digits[i] = mapping[digits[i]];
        }
        return parseInt(digits.join(''));
    };

    const Mapping = {};
    for (let num of nums) {
        if (!(num in Mapping)) {
            Mapping[num] = translate(num);
        }
    }

    nums.sort((a, b) => Mapping[a] - Mapping[b]);

    return nums;
};