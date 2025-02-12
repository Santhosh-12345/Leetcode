class Solution {
public:
    int find(int num)
    {
        int s=0;
        while(num>0)
        {
            s+=num%10;
            num=num/10;
        }
        return s;
    }
    int maximumSum(vector<int>& nums) {
        int maxi=-1;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++)
        {
            int totalSum=find(nums[i]);
            if(mpp.find(totalSum)!=mpp.end())
            {
                maxi=max(maxi,mpp[totalSum]+nums[i]);
                mpp[totalSum]=max(mpp[totalSum],nums[i]);
            }
            else
            mpp[totalSum]=nums[i];
        }   
        

        return maxi;
    }
};