#include <unordered_set>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> st;
        int l = 0, sum = 0, maxSum = 0;

        for (int r = 0; r < nums.size(); r++) {
            while (st.find(nums[r]) != st.end()) {
                st.erase(nums[l]);
                sum -= nums[l];
                l++;
            }
            st.insert(nums[r]);
            sum += nums[r];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
