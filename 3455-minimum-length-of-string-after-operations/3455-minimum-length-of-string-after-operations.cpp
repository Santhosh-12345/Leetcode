class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int count=0;
        int freq[26]={0};
        for(int i=0;i<n;i++)
        {
            freq[s[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if (freq[i] > 0) {
                count += (freq[i] % 2 == 0) ? 2 : 1;
            
        }
        }
        return count;
    }
};
