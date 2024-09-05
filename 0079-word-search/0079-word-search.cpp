class Solution {
public:
    bool solve(int i,int j,vector<vector<char>>&board,string &s,vector<vector<bool>>&visited,int index)
    {
        visited[i][j]=true;
        if(index==s.size()-1)
        return true;
        
        if(i>0 && board[i-1][j]==s[index+1] && !visited[i-1][j] && solve(i-1,j,board,s,visited,index+1))
        return true;
        if(j>0 && board[i][j-1]==s[index+1] && !visited[i][j-1] && solve(i,j-1,board,s,visited,index+1))
        return true;
        if(i<board.size()-1 && board[i+1][j]==s[index+1] && !visited[i+1][j] && solve(i+1,j,board,s,visited,index+1))
        return true;
        if(j<board[0].size()-1 && board[i][j+1]==s[index+1] && !visited[i][j+1] && solve(i,j+1,board,s,visited,index+1))
        return true;

        visited[i][j]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int r=board.size();
        int c=board[0].size();
        vector<vector<bool>>visited(r,vector<bool>(c,false));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]==word[0] &&solve(i,j,board,word,visited,0)==true)
                return true;
            }
        }
        return false;
    }
};