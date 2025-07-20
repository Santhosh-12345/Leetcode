class Solution {
public:
    int func(int ind,vector<int>&nums,vector<int>& dp)
    {
        if(ind>=nums.size())
        {
            return 0;
        }
        if(dp[ind]!=-1)
        return dp[ind];
        int pick=nums[ind]+func(ind+2,nums,dp);
        int skip=0+func(ind+1,nums,dp);
        return dp[ind]=max(skip,pick);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        if(nums.size()==0)
        return 0;
        return func(0,nums,dp);
    }
};