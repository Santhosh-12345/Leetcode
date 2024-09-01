class Solution {
public:
    void func(int start,int k,int n,vector<vector<int>>&ans,vector<int>&ds)
    {
        if(k==0 && n==0)
        {
            ans.push_back(ds);
            return;
        }
        if(k==0 || n<=0)
        {
            return;
        }
        for(int i=start;i<=9;i++)
        {
            if(i>n)
            break;
            ds.push_back(i);
            func(i+1,k-1,n-i,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;
        func(1,k,n,ans,ds);
        return ans;
    }
};