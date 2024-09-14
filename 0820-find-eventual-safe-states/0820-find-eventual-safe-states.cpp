class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        queue<int>q;
        int v=graph.size();
        vector<int>indegree(v,0);
        vector<int>ans;
        vector<vector<int>>adjRev(v);
        for(int i=0;i<v;i++)
        {
            for(auto it:graph[i])
            {
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        for(int i=0;i<v;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto it:adjRev[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};