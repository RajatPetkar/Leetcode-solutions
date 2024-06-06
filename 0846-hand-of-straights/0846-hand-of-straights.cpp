class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int size = hand.size();
        if (size % groupSize != 0) return false;

    map<int, int> countMap;
    for (int card : hand) {
        countMap[card]++;
    }
        
    for (auto it = countMap.begin(); it != countMap.end(); ++it) {
        int startCard = it->first;
        int cardCount = it->second;

        if (cardCount > 0) {
            for (int i = 0; i < groupSize; ++i) {
                if (countMap[startCard + i] < cardCount) return false;
                countMap[startCard + i] -= cardCount;
            }
        }
    }

    return true;
    }
};