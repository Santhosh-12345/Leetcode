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
        return parent[x]=findParent(parent[x]);
    }
    void unionSets(int u,int v)
    {
        int pu=findParent(u);
        int pv=findParent(v);
        if(pu==pv)
        return;
        if(rank[pu]>rank[pv])
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
    int removeStones(vector<vector<int>>& stones) {
        int row=0,col=0;
        for(auto it:stones)
        {
            row=max(row,it[0]);
            col=max(col,it[1]);
        }
        disjoint ds(row+col+2);
        unordered_map<int,int>mpp;
        for(auto it:stones)
        {
            int node1=it[0];
            int node2=it[1]+row+1;
            ds.unionSets(node1,node2);
            mpp[node1]=1;
            mpp[node2]=1;
        }
        int count=0;
        
        for(auto it:mpp)
        {
            if(ds.findParent(it.first)==it.first)
            count++;
        }
        return stones.size()-count;
    }
};