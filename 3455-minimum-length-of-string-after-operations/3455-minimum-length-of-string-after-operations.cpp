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
            if(freq[i]==0)
            continue;
            if(freq[i]%2==0)
            count+=2;
            else if(freq[i]%2!=0)
            count+=1;
        }
        return count;
    }
};
