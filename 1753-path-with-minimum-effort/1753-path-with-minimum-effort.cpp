class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        pq.push({0,{0,0}});
        dist[0][0]=0;
        int drow[]={0,0,1,-1};
        int dcol[]={-1,1,0,0};
        while(!pq.empty())
        {
            auto it=pq.top();
            int len=it.first;
            int r=it.second.first;
            int c=it.second.second;
            pq.pop();
            if(r==n-1 && c==m-1)
            return len;
            for(int i=0;i<4;i++)
            {
                int newr=r+drow[i];
                int newc=c+dcol[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m)
                {
                    int newlen=max(len,abs(heights[r][c]-heights      [newr][newc]));
                    if(newlen<dist[newr][newc])
                    {
                        dist[newr][newc]=newlen;
                        pq.push({newlen,{newr,newc}});
                    }
                }
            }
        }
        return -1;
    }
};