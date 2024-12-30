class Solution {
public:
    int func(vector<int>&dp,int low, int high, int zero, int one,int length){
        if(length>high)
        return 0;
        if(dp[length]!=-1)
        return dp[length];
        int count=0,MOD=1e9+7;
        if(length>=low && length<=high)
        count+=1;
        count+=func(dp,low,high,zero,one,length+zero);
        count+=func(dp,low,high,zero,one,length+one);
        return dp[length]=count%MOD;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1,-1);
        return func(dp,low,high,zero,one,0);
    }
};