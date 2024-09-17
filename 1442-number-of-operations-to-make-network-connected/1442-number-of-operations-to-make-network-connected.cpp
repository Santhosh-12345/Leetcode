class disjoint{
    vector<int>parent;
    vector<int>rank;
    public:
    disjoint(int n)
    {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
        parent[i]=i;
    }
    int findParent(int x)
    {
        if(x==parent[x])
        return x;
        return findParent(parent[x]);
    }
    void unionSets(int u,int v)
    {
        int pu=findParent(u);
        int pv=findParent(v);
        if(pu==pv)
        return;
        else if(rank[pu]>rank[pv])
        parent[pv]=pu;
        else if(rank[pv]>rank[pu])
        parent[pu]=pv;
        else
        {
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extra=0,ans=0;
        disjoint ds(n);
        for(auto it:connections)
        {
            int u=it[0];
            int v=it[1];
            if(ds.findParent(u)==ds.findParent(v))
            extra++;
            else
            ds.unionSets(u,v);
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(ds.findParent(i)==i)
            ans++;
        }
        if(extra>=ans-1)
        return ans-1;
        return -1;
    }
};