class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& board,vector<vector<int>>& vis,int n,int m)
    {
        vis[r][c]=1;
        int di[4]={+1,0,0,-1};
        int dj[4]={0,-1,+1,0};
        for(int i=0;i<4;i++)
        {
            int drow=r+di[i];
            int dcol=c+dj[i];
            if(drow>=0 && drow<n && dcol>=0 && dcol<m && !vis[drow][dcol] && board[drow][dcol]=='O')
            {
                dfs(drow,dcol,board,vis,n,m);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O' && !vis[i][0])
            dfs(i,0,board,vis,n,m);
            if(board[i][m-1]=='O' && !vis[i][m-1])
            dfs(i,m-1,board,vis,n,m);
        }
        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O' && !vis[0][j])
            dfs(0,j,board,vis,n,m);
            if(board[n-1][j]=='O' && !vis[n-1][j])
            dfs(n-1,j,board,vis,n,m);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && !vis[i][j])
                {
                    board[i][j]='X';
                }
            }
        }
    }
};