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
    vector<vector<string>> accountsMerge(vector<vector<string>>& details){
        unordered_map<string,int>mpp;
        int n=details.size();
        disjoint ds(n);
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<details[i].size();j++)
            {
                string mail=details[i][j];
                if(mpp.find(mail)==mpp.end())
                mpp[mail]=i;
                else
                ds.unionSets(i,mpp[mail]);
            }
        }
        vector<string>merged[n];
        for(auto it:mpp)
        {
            string mail=it.first;
            int node=ds.findParent(it.second);
            merged[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++)
        {
            vector<string>temp;
            if(merged[i].size()==0)
            continue;
            sort(merged[i].begin(),merged[i].end());
            temp.push_back(details[i][0]);
            for(auto it:merged[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};