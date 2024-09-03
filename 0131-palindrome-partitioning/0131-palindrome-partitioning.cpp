class Solution {
public:
    void func(int index,vector<vector<string>>&ans,vector<string>&path,string s)
    {
        if(index==s.size())
        {
            ans.push_back(path);
            return;
        }
        for(int i=index;i<s.size();i++)
        {
            if(isPalindrome(index,i,s))
            {
                path.push_back(s.substr(index,i-index+1));
                func(i+1,ans,path,s);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(int start,int end,string s)
    {
        while(start<end)
        {
            if(s[start]!=s[end])
            return false;
            start++;
            end--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        func(0,ans,path,s);
        return ans;
    }
};