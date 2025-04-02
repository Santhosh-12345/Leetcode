class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[n-1];
        vector<int>right_max(n,0);
        for(int i=n-2;i>0;i--)
        {
            right_max[i]=maxi;
            maxi=max(maxi,nums[i]);
        }
        long long ans=0;
        int left_max=nums[0];
        for(int i=1;i<=n-2;i++)
        {
            ans=max(ans,1ll*(left_max-nums[i])*right_max[i]);
            left_max=max(left_max,nums[i]);
        }
        return ans;
    }
};