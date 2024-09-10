class Solution {
public:
    void dfs(int Node,vector<vector<int>>&adjList,vector<int>&vis)
    {
        vis[Node]=1;
        for(auto it:adjList[Node])
        {
            if(!vis[it])
            dfs(it,adjList,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size(),count=0;
        vector<int>vis(V,0);
        vector<vector<int>>adjList(V);
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected[0].size();j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(i,adjList,vis);
            }
        }
        return count;
    }
};