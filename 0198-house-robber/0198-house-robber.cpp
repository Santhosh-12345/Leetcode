class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];
        vector<int>dp(nums.size()+1,-1);
        int prev1=nums[0];
        int prev=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++)
        {

            int cost=nums[i]+prev1;
            int cost1=prev;
            int curr=max(cost,cost1);
            prev1 =prev;
            prev=curr;
        }
        return prev;
    }
};