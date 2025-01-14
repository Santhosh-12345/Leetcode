class Solution {
public:
    int c0(string s)
    {
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')
            count++;
        }
        return count;
    }
    int c1(string s)
    {
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            count++;
        }
        return count;
    }
    int maxScore(string s) {
        int n=s.size();
        int maxi=0;
        for(int i=0;i<n-1;i++)
        {
            string left = s.substr(0, i+1);
            string right = s.substr(i+1);

            int score = c0(left) + c1(right);
            maxi = max(maxi, score);
        }
        return maxi;
    }
};