class Solution {
public:
    int func(int n,vector<int>&nums,vector<int>&dp)
    {
        if(n<0)
        return 0;
        if(n==0)
        return nums[0];
        if(dp[n]!=-1)
        return dp[n];
        int pick=nums[n]+func(n-2,nums,dp);
        int notpick=func(n-1,nums,dp);
        return dp[n]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return nums[0];
        vector<int>dp1(n-1,-1),dp2(n-1,-1);
        vector<int>arr1(nums.begin()+1,nums.end());
        vector<int>arr2(nums.begin(),nums.end()-1);
       
        return max(func(n-2,arr1,dp1),func(n-2,arr2,dp2));
    }
};