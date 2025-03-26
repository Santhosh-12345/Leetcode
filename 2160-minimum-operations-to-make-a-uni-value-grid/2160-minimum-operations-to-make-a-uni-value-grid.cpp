class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>arr;
        int n=grid.size(),m=grid[0].size();
        int rem=grid[0][0]%x;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]%x!=rem)
                return -1;
                arr.push_back(grid[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        int median=arr.size()/2;
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            ans+=abs(arr[median]-arr[i])/x;
        }
        return ans;
    }
};