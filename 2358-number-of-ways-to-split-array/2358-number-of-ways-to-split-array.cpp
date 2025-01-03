class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        long long left=0,right=0,total=0;
        int count=0;
        for(int n:nums)
        total+=n;
        for(int i=0;i<n-1;i++){
            left+=nums[i];
            right=total-left;
            if(left>=right)
            count++;
        }
        return count;
    }
};