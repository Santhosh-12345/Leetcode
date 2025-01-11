class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k>s.size())
        return false;
        int freq[26]={0};
        for(char c:s)
        {
            freq[c-'a']++;
        }
        int count=0;
        for(int i=0;i<26;i++)
        {
            if(freq[i]%2!=0)
            count++;
        }
        return count<=k;
    }
};