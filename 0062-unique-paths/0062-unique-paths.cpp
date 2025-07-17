class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m + n - 2;     // Total moves
        int r = min(m - 1, n - 1);   // Choose smaller of down or right moves

        long long result = 1;   // To prevent overflow

        for(int i = 1; i <= r; i++) {
            result = result * (N - i + 1);
            result = result / i;
        }

        return (int)result;
    }
};
