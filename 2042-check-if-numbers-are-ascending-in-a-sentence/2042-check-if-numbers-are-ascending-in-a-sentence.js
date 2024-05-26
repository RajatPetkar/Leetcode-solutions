/**
 * @param {string} s
 * @return {boolean}
 */
const areNumbersAscending = (s) => {
    const sArr = s.split(" ");
    let temp = 0;
    for (let i = 0; i < sArr.length; i++) {
        const element = +sArr[i];
        if (isNaN(element)) continue;
        if (element > temp) temp = element;
    else return false;
    }
    return true;
};