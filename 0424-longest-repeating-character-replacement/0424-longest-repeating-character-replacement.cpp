class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        vector<int>hash(26,0);
        int l=0,r=0,ans=0,maxf=0;
        while(r<n)
        {
            hash[s[r]-'A']++;
            maxf=max(maxf,hash[s[r]-'A']);
            int len=r-l+1;
            if(len-maxf>k)
            {
                hash[s[l]-'A']--;
                l++;
            }
             ans = max(ans, r - l + 1);

            r++;
        }
        return ans;
    }
};