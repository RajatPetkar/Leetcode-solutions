/**
 * @param {string[]} details
 * @return {number}
 */
var countSeniors = function(details) {
    let count = 0;
    for (let i = 0; i < details.length; i++) {
        let age = details[i].substring(11, 13); 
        if (Number(age) > 60) {
            count++;
        }
    }
    return count;
};