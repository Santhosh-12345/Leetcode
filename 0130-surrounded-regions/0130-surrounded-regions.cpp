class Solution {
    private:
    void dfs(vector<vector<char>>& board,int i,int j,vector<vector<int>>&vis,int drow[],int dcol[],int n,int m )
    {
        vis[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int nrow=i+drow[k];
            int ncol=j+dcol[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O' && vis[nrow][ncol]==0)
            {
                dfs(board,nrow,ncol,vis,drow,dcol,n,m);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int drow[]={-1,1,0,0},dcol[]={0,0,1,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O' && !vis[0][j])
            dfs(board,0,j,vis,drow,dcol,n,m);
            if(board[n-1][j]=='O' && !vis[n-1][j])
            dfs(board,n-1,j,vis,drow,dcol,n,m);
        }
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O' && !vis[i][0])
            dfs(board,i,0,vis,drow,dcol,n,m);
            if(board[i][m-1]=='O' && !vis[i][m-1])
            dfs(board,i,m-1,vis,drow,dcol,n,m);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && vis[i][j]==0)
                board[i][j]='X';
            }
        }
    }
};