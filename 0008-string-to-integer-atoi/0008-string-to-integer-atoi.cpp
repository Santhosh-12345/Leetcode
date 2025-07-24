class Solution {
public:
    int myAtoi(string s) {
        long ans=0;
        int i=0,n=s.size();
        int sign=1;
        while(i<n && s[i]==32)
        {
            i++;
        }
        if (i < n && (s[i] == '-' || s[i] == '+')) 
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;    
        }
        while(i<n && (s[i]>='0' && s[i]<='9'))
        {
            ans = ans * 10 + (s[i] - '0');
            if(sign==-1 && -ans<INT_MIN)
            return INT_MIN;
            if(sign==1 && ans>INT_MAX)
            return INT_MAX;
            i++;
        }
        return (int)sign*ans;
    }
};