class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n, 0);
        
        // Calculate leftSum and rightSum, and update the result in a single pass.
        int leftSum = 0, rightSum = 0;
        int leftCount = 0, rightCount = 0;
        
        // Traverse from left to right
        for (int i = 0; i < n; i++) {
            res[i] += leftSum;  // Add left sum of moves
            leftCount += (boxes[i] == '1' ? 1 : 0);  // Count balls on the left
            leftSum += leftCount;  // Update left sum (accumulating ball moves)
        }
        
        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            res[i] += rightSum;  // Add right sum of moves
            rightCount += (boxes[i] == '1' ? 1 : 0);  // Count balls on the right
            rightSum += rightCount;  // Update right sum (accumulating ball moves)
        }
        
        return res;
    }
};
