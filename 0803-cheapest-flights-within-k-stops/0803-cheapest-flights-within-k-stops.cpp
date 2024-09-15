class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,pair<int,int>>>q;
        vector<pair<int,int>> adj[n];
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>distance(n,1e9);
        q.push({0,{src,0}});
        distance[src]=0;
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int dist=it.second.second;
            if(stops>k)
            continue;
            for(auto iter:adj[node])
            {
                int adjNode=iter.first;
                int weight=iter.second;
                if(dist+weight<distance[adjNode] && stops<=k)
                {
                    distance[adjNode]=dist+weight;
                    q.push({stops+1,{adjNode,dist+weight}});
                }
            }
        }
        if(distance[dst]==1e9)
        return -1;
        return distance[dst];
    }
};