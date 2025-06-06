class Solution {
public:
    int climbStairs(int n) {
        if(n==0)
        return 1;
        if(n==1)
        return 1;
        int prev2=1,prev1=1;
        for(int i=2;i<=n;i++)
        {
            int curr=prev2+prev1;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};