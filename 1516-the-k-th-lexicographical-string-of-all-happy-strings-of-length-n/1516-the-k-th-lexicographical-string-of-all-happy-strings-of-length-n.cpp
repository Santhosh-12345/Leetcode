class Solution {
public:
    void func(int n,string &ans,int ind,int &counter,string &result,int k)
    {
        if(ind==n)
        {
            counter++;
            if(counter==k)
            result=ans;
            return;
        }
        for(char ch='a';ch<='c';ch++)
        {
            if(ind==0 || ans[ind-1]!=ch)
            {
                ans[ind]=ch;
                func(n,ans,ind+1,counter,result,k);
                ans[ind]=' ';
            }
        }
    }
    string getHappyString(int n, int k) {
        string ans(n,' ');
        string result="";
        int counter=0;
        func(n,ans,0,counter,result,k);
        return result;
    }
};