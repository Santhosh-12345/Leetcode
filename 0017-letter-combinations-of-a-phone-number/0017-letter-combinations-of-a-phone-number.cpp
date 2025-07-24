class Solution {
public:
    void func(string& digits,int index,vector<string>& ans,string& temp,vector<string>& mpp)
    {
        if(index==digits.size())
        {
            ans.push_back(temp);
            return;
        }
        string val=mpp[digits[index]-'0'];
        for(int i=0;i<val.size();i++)
        {
            temp.push_back(val[i]);
            func(digits,index+1,ans,temp,mpp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        vector<string>mpp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits.size()==0)
        return ans;
        string temp;
        func(digits,0,ans,temp,mpp);
        return ans;

    }
};