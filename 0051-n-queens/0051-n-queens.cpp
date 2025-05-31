class Solution {
public:
    void solve(int col,vector<vector<string>>&ans,vector<string>&board,int n,
    vector<int>&left,vector<int>&lower,vector<int>&upper)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        //left
        for(int row=0;row<n;row++)
        {
            if(left[row]==0 && lower[row+col]==0 && upper[n-1+col-row]==0)
            {
                board[row][col]='Q';
                left[row]=1;
                lower[row+col]=1;
                upper[n-1+col-row]=1;
                solve(col+1,ans,board,n,left,lower,upper);
                board[row][col]='.';
                left[row]=0;
                lower[row+col]=0;
                upper[n-1+col-row]=0;
            }
        }
        //lower
        //upper
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        vector<int>left(n,0),lower(2*n-1,0),upper(2*n-1,0);
        solve(0,ans,board,n,left,lower,upper);
        return ans;
    }
};