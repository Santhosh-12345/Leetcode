class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
           int n=mat.size(),m=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
                else
                {
                    vis[i][j]=0;
                }
            }
        }
        while(!q.empty())
        {
            int first=q.front().first.first,second=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            ans[first][second]=steps;
            int delrow[]={0,1,-1,0};
            int delcol[]={-1,0,0,1};
            for(int i=0;i<4;i++)
            {
                int drow=first+delrow[i];
                int dcol=second+delcol[i];
                if(drow>=0 && drow<n && dcol>=0 && dcol<m && vis[drow][dcol]==0)
                {
                    vis[drow][dcol]=1;
                    q.push({{drow,dcol},steps+1});
                }
            }
        }
        return ans;
    }
};