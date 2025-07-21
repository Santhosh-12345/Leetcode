class Solution {
public:
    int func(string& text1,string& text2,int i,int j,vector<vector<int>>& dp)
    {
        if(i==text1.size() || j==text2.size())
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(text1[i]==text2[j])
        return dp[i][j]=1+func(text1,text2,i+1,j+1,dp);
        return dp[i][j]=max(func(text1,text2,i+1,j,dp),func(text1,text2,i,j+1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return func(text1,text2,0,0,dp);   
    }
};