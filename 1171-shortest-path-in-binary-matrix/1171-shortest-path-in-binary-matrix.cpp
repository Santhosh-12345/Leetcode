class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]!=0 || grid[n-1][m-1]!=0)
        return -1;
        if(n==1 && m==1)
        {
            if(grid[0][0]==0)
            return 1;
            else 
            return -1;
        }
        int drow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dcol[] = {0, 1, 1, 1, 0, -1, -1, -1};
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=1;
        q.push({1,{0,0}});
        while(!q.empty())
        {
            int len=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(int i=0;i<8;i++)
            {
                int newr=row+drow[i];
                int newc=col+dcol[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m &&
                grid[newr][newc]==0 && 1+len<dist[newr][newc])
                {
                     dist[newr][newc]=1+len;
                    if(newr==n-1 && newc==m-1)
                    return 1+len;
                    q.push({1+len,{newr,newc}});
                }
            }
        }
        return -1;
    }
};