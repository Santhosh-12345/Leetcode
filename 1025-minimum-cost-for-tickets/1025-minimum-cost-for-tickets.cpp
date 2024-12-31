class Solution {
public:
    int func(int ind,vector<int>& days, vector<int>& cost,vector<int>&dp)
    {
        if(ind>=days.size())
        return 0;
        if(dp[ind]!=-1)
        return dp[ind];
        int cost1=cost[0]+func(ind+1,days,cost,dp);
        int j=ind;
        while(j<days.size() && days[j]<days[ind]+7)
        j++;
        int cost2=cost[1]+func(j,days,cost,dp);
        int k=ind;
        while(k<days.size() && days[k]<days[ind]+30)
        k++;
        int cost3=cost[2]+func(k,days,cost,dp);
        return dp[ind]=min({cost1,cost2,cost3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+1,-1);
        return func(0,days,costs,dp);
    }
};