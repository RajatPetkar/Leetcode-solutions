/**
 * @param {string} order
 * @param {string} s
 * @return {string}
 */
var customSortString = function (order, string) {
  let map = {};
  for (let i = 0; i < order.length; i++) {
    map[order[i]] = i;
  }
  for (let i = 0; i < string.length; i++) {
    if (map[string[i]] == undefined) {
      map[string[i]] = Infinity;
    }
  }
  string = string.split("");
 return string.sort((a, b) => map[a] - map[b]).join(""); 
};