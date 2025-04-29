class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        long long res=0;
        int maxi=*max_element(nums.begin(),nums.end());
        int left=0,count=0;
        for(int right=0;right<n;right++)
        {
            if(nums[right]==maxi)
            count++;
            while(count>=k)
            {
                res+=n-right;
                if(nums[left]==maxi)
                count--;
                left++;
            }
        }   
        return res;
    }
};