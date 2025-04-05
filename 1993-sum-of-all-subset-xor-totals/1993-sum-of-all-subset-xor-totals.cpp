class Solution {
public:
    void dfs(vector<int>& nums, int index, int currXor, int& total) {
    if (index == nums.size()) {
        total += currXor;
        return;
    }

    // Include current number
    dfs(nums, index + 1, currXor ^ nums[index], total);

    // Exclude current number
    dfs(nums, index + 1, currXor, total);
}

int subsetXORSum(vector<int>& nums) {
    int total = 0;
    dfs(nums, 0, 0, total);
    return total;
    }
};