class Solution {
public:
string res;
    bool fun(int n,string &curr,unordered_set<string> &st)
    {
        if(curr.size()==n)
        {
            if(st.find(curr)==st.end())
            {
                res=curr;
                return true;
            }
            return false;
        }
        curr.push_back('0');
        if(fun(n,curr,st))
        return true;
        curr.pop_back();

        curr.push_back('1');
        if(fun(n,curr,st))
        return true;
        curr.pop_back();

        return false;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        string curr="";
        unordered_set<string>st(nums.begin(),nums.end());
        int n=nums[0].size();
        fun(n,curr,st);
        return res;
    }
};