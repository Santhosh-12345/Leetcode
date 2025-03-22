class Solution {
public:
    void dfs(int i,vector<bool>&vis,int& e,int& node,vector<vector<int>>&adj)
    {
        node++;
        vis[i]=true;
        for(auto it:adj[i])
        {
            e++;
            if(!vis[it])
            {
                dfs(it,vis,e,node,adj);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans=0;
        vector<bool>vis(n,false);
        vector<vector<int>>adj(n);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i]){
                int node=0,e=0;
                dfs(i,vis,e,node,adj);
                if(e==node*(node-1))
                ans+=1;
            }
        }
        return ans;
    }
};