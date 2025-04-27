class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();

        // Iterate through all valid i for subarrays of length 3
        for (int i = 0; i < n - 2; i++) {
            // Check only the valid subarrays of length 3 (nums[i], nums[i+1], nums[i+2])
            int j = i + 1;
            int k = i + 2;

            // Check if the condition holds (you can adjust this condition if needed)
            if (2 * (nums[i] + nums[k]) == nums[j]) {
                cnt++;
            }
        }

        return cnt;
    }
};
