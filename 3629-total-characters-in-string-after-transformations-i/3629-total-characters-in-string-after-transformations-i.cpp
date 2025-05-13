class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int res=0;
        int mod=1e9+7;
        vector<int>arr(26,0);
        for(char c:s)
        arr[c-'a']++;
        while(t>0)
        {
            vector<int>temp(26,0);
            for(int i=0;i<25;i++)
            {
                temp[i+1]=arr[i];
            }
            temp[0]=(arr[25]+temp[0])%mod;
            temp[1]=(arr[25]+temp[1])%mod;
            arr=temp;
            t--;
        }
        for(int n:arr)
        {
            res=(res+n)%mod;
        }
        return res;
    }
};