/**
 * @param {string} s
 * @return {boolean}
 */
var isNumber = function(s) {
    const numberRegex = /^[+\-]?(\d+(\.\d*)?|\.\d+)([eE][+\-]?\d+)?$/;
    
    return numberRegex.test(s);
};