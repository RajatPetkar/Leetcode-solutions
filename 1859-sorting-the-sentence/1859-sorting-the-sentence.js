/**
 * @param {string} s
 * @return {string}
 */
var sortSentence = function(s) {
    const sArr = s.split(" ");

    sArr.sort((a, b) => {
        const numA = parseInt(a[a.length - 1]);
        const numB = parseInt(b[b.length - 1]);
        return numA - numB;
    });

    for (let i = 0; i < sArr.length; i++) {
        sArr[i] = sArr[i].substring(0, sArr[i].length - 1);
    }

    return sArr.join(" ");
};


