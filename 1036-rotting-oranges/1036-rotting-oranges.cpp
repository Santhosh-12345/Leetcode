class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
         int totaltm=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
                else
                vis[i][j]=0;
            }
        }
            int drow[]={-1,0,1,0},dcol[]={0,1,0,-1};
           
            while(!q.empty())
            {
                int node1=q.front().first.first,node2=q.front().first.second,t=q.front().second;
                totaltm=max(totaltm,t);
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int nrow=node1+drow[i];
                    int ncol=node2+dcol[i];
                    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1 && vis[nrow][ncol]!=2)
                    {
                        vis[nrow][ncol]=2;
                        q.push({{nrow,ncol},t+1});
                    }
                }
            }
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(grid[i][j]==1 && vis[i][j]!=2)
                    return -1;
                }
            }
        
        return totaltm;
    }
};