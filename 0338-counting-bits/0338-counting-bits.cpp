class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++)
        {
            int cnt=0;
            int temp=i;
            while(temp>0)
            {
                temp=temp &(temp-1);
                cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};