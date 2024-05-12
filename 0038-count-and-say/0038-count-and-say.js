/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
    if (n === 1) return '1';
    
    const current = countAndSay(n - 1);
    let newOutput = '';
    let currentNumber = current[0];
    let count = 0;
    for (let i = 0; i <= current.length; i++) {
        if (current[i] === currentNumber) {
            count++;
        } else if (currentNumber) {
            newOutput += `${count}${currentNumber}`;
            
            currentNumber = current[i];
            count = 1;
        }
    }
    
    return newOutput;
};