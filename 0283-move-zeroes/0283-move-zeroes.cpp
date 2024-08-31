class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i,j=-1;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                j=i;
                break;
            }
        }
        for(i=j;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                swap(nums[i],nums[j]);
                j++;
            }
            
        }
    }
};