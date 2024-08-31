class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,backInd=-1;
        for(i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {backInd=i; break;}
        }
        if(backInd==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        for(i=nums.size()-1;i>backInd;i--)
        {
            if(nums[i]>nums[backInd])
            {
                swap(nums[i],nums[backInd]);
                break;
            }
        }
        reverse(nums.begin()+backInd+1,nums.end());
    }
};