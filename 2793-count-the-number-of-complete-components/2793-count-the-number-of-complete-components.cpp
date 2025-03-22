class Solution {
public:
    void dfs(int i, vector<bool>& vis, int &e, int &n, vector<vector<int>>& adj) {
        n++; 
        vis[i] = true;  
        for(auto it : adj[i]) {
            e++;  
            if(!vis[it]) {
                dfs(it, vis, e, n, adj);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<bool> vis(n, false); 
        vector<vector<int>> adj(n);

        // Build adjacency list
        for(auto& it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // Traverse all nodes
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                int compNodes = 0, compEdges = 0;
                dfs(i, vis, compEdges, compNodes, adj);
                
                // Correct edge count: each edge is counted twice in an undirected graph
                if (compEdges / 2 == compNodes * (compNodes - 1) / 2)
                    ans++;
            }
        }

        return ans;
    }
};
