class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int ans=0,l_end=0;
        sort(meetings.begin(),meetings.end());
        for(auto it:meetings)
        {
            int s=it[0];
            int e=it[1];
            if(s>l_end+1)
            {
                ans+=(s-l_end-1);
            }
            l_end=max(l_end,e);
        }
        ans+=(days-l_end);
        return ans;
    }
};