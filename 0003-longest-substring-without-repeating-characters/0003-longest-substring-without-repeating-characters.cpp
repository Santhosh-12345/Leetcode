class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int l=0,maxi=0;
        unordered_map<char,int>mpp;
        for(int r=0;r<str.size();r++)
        {
            if(mpp.find(str[r])==mpp.end())
            {
                mpp[str[r]]=r;
                
            }
            else
            {
                l=max(l,mpp[str[r]]+1);
                mpp[str[r]]=r;
            }
            maxi=max(maxi,r-l+1);
        }
        return maxi;
    }
};