/**
 * @param {number} numBottles
 * @param {number} numExchange
 * @return {number}
 */
var numWaterBottles = function(numBottles, numExchange) {
       let drunk = numBottles;
    while (numBottles >= numExchange){ 
        drunk += Math.floor(numBottles / numExchange);
        numBottles = Math.floor(numBottles / numExchange) + numBottles % numExchange;
    }
    return drunk
};