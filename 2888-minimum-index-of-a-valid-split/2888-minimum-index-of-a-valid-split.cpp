class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        int el=nums[0],cnt=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==el)
            cnt++;
            else
            cnt--;
            if(cnt==0)
            {
                el=nums[i];
                cnt=1;
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==el)
            count++;
        }
        int pre=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==el)
            pre++;
            if(pre*2>(i+1) &&  (count-pre)*2>(n-i-1))
            return i;
        }
        return -1;
    }
};