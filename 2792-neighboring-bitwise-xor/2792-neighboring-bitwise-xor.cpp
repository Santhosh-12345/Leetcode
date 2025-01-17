class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
       int xorSum = 0;
        for (int val : derived) {
            xorSum ^= val;
        }
        // If XOR of all elements in derived is 0, a valid original array exists
        return xorSum == 0;
    }
};