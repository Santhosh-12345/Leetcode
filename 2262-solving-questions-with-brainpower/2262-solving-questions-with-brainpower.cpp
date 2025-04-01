class Solution {
public:
     long long func(int ind,vector<vector<int>>& questions,vector<long long>& dp)
    {
        if(ind>=questions.size())
        {
            return 0;
        }
        if(dp[ind]!=-1)
        return dp[ind];
        long long pick=questions[ind][0]+func(ind+questions[ind][1]+1,questions,dp);
        long long notpick=func(ind+1,questions,dp);
        return dp[ind]=max(pick,notpick);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        if(questions.size()==0)
        return 0;
        vector<long long>dp(questions.size(),-1);
        return func(0,questions,dp);
    }
};