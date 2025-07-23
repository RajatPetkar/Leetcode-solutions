class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drunk = numBottles;
        while(numBottles >= numExchange){
            drunk += (numBottles / numExchange);
            numBottles = (numBottles / numExchange) + numBottles % numExchange;
        }
        return drunk;
    }
};