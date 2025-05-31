class Solution {
public:
    void solve(int col,vector<vector<string>>&ans,vector<string>&board,int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        //left
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,board,n))
            {
                board[row][col]='Q';
                solve(col+1,ans,board,n);
                board[row][col]='.';
            }
        }
        //lower
        //upper
    }
    bool isSafe(int i,int j,vector<string>&board,int n)
    {
        int di=i;
        int dj=j;
        //left
        while(j>=0)
        {
            if(board[i][j]=='Q')
            return false;
            j--;
        }
        i=di;
        j=dj;
        //upper
        while(i>=0 && j>=0)
        {
            if(board[i][j]=='Q')
            return false;
            i--;
            j--;
        }
        i=di;
        j=dj;
        //lower
        while(i<n && j>=0)
        {
            if(board[i][j]=='Q')
            return false;
            i++;
            j--;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        solve(0,ans,board,n);
        return ans;
    }
};