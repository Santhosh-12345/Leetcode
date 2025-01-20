class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        unordered_map<int,pair<int,int>>mpp;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mpp[mat[i][j]]={i,j};
            }
        }
        vector<int>row(m,0);
        vector<int>col(n,0);
        for(int i=0;i<arr.size();i++)
        {
            auto it=mpp[arr[i]];
            int r=it.first;
            int c=it.second;
            row[r]++;
            col[c]++;
            if(row[r]==n || col[c]==m)
            return i;
        }
        return -1;
    }
};