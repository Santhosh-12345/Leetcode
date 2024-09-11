class Solution {
public:
    void dfs(vector<vector<int>>&ans,int color,vector<vector<int>>&image,int row,int col,int initial)
    {
        ans[row][col]=color;
        int drow[]={-1,0,1,0},dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<image.size() && ncol>=0 && ncol<image[0].size() && ans[nrow][ncol]!=color && image[nrow][ncol]==initial)
            dfs(ans,color,image,nrow,ncol,initial);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        int initial=image[sr][sc];
        dfs(ans,color,image,sr,sc,initial);
        return ans;
    }
};