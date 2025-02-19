class Solution {
public:
    void func(int n,string &ans,int ind,vector<string> &happy)
    {
        if(ind==n)
        {
            happy.push_back(ans);
            return;
        }
        for(char ch='a';ch<='c';ch++)
        {
            if(ind==0 || ans[ind-1]!=ch)
            {
                ans[ind]=ch;
                func(n,ans,ind+1,happy);
                ans[ind]=' ';
            }
        }
    }
    string getHappyString(int n, int k) {
        string ans(n,' ');
        vector<string> happy;
        func(n,ans,0,happy);
        if(k>happy.size())
        return "";
        return happy[k-1];
    }
};