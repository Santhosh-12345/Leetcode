class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mpp={{'I',1},{'V',5},{'X',10},
        {'L',50},{'C',100},{'D',500},{'M',1000}};
        int ans=0;
        int prev=0;
        for(int i=s.size();i>=0;i--)
        {
            if(prev>mpp[s[i]])
            {
                ans-=mpp[s[i]];
            }
            else
            {
                ans+=mpp[s[i]];
            }
            prev=mpp[s[i]];
        }
        return ans;
    }
};