class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count=0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int l=0,r=0;
        int n=g.size(),m=s.size();
        while(l<n && r<m)
        {
            if(g[l]<=s[r])
            {
                l++;
                count++;
            }
            r++;
        }
        return count;
    }
};