class Solution {
public:
    int getLucky(string s, int k) {
        int i=0,sum;
        string ans="";
        while(i<s.size())
        {
            ans+=to_string(s[i]-96);
            i++;
        }
        i=0;
        while(k>0)
        {
            sum=0;
            for(char ch:ans)
            {
                sum+=ch-'0';
            }
            ans=to_string(sum);
            k--;
        }
        return stoi(ans);
    }
};