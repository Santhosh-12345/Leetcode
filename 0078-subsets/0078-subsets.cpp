class Solution {
public:
    void func(int ind,vector<int>nums,vector<vector<int>>&ans,vector<int>&current)
    {
        if(ind==nums.size())
        {
            ans.push_back(current);
            return;
        }
        current.push_back(nums[ind]);
        func(ind+1,nums,ans,current);
        current.pop_back();
        func(ind+1,nums,ans,current);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>current;
        func(0,nums,ans,current);
        return ans; 
    }
};