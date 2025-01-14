class Solution {
public:
    int maxScore(string s) {
        int total_ones = 0;
        for (char c : s) {
            if (c == '1') total_ones++;
        }

        int left_zeros = 0, right_ones = total_ones;
        int max_score = 0;

        // Iterate over splits (n-1 splits since both substrings must be non-empty)
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '0') {
                left_zeros++;
            } else {
                right_ones--;
            }

            // Calculate the current score
            int score = left_zeros + right_ones;
            max_score = max(max_score, score);
        }

        return max_score;
    }
};
