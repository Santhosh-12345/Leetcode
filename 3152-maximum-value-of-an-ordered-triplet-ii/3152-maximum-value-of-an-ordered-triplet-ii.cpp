class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long max_trip=0,max_diff=0,left_max=0;
        for(int i=0;i<n;i++)
        {
            max_trip=max(max_trip,1ll*max_diff*nums[i]);
            max_diff=max(max_diff,left_max-nums[i]);
            left_max=max(left_max,1ll*nums[i]);
        }
        return max_trip;
    }
};