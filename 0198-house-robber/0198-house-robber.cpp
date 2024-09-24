class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return func(nums.size()-1,nums,dp);
    }
    int func(int n,vector<int>& nums,vector<int>&dp)
    {
        if(n==0)
        return nums[n];
        if(n<0)
        return 0;
        if(dp[n]!=-1)
        return dp[n];
        int cost=nums[n]+func(n-2,nums,dp);
        int cost1=0+func(n-1,nums,dp);
        return dp[n]=max(cost,cost1);
    }
};