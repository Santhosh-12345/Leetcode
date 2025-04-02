class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int i,j,k;
        long long maxi=LLONG_MIN;
        int n=nums.size();
        for(i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    long long sum=(long long)(nums[i]-nums[j])*nums[k];
                    maxi=max(sum,maxi);
                }
            }
        }
        return maxi>0? maxi:0;
    }
};