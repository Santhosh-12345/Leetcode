class Solution {
public:
vector<int>parent;
vector<int> rank;    // To store the rank (height) of the tree for each node
    int group; 
    int find(int i)
    {
        while (i != parent[i]) {
        i = parent[i];
    }
    return i;
    }
    void union1(int i,int j)
    {
        int pi=find(i);
        int pj=find(j);
        if(pi==pj)
        return;
        if(rank[pi]>rank[pj])
        {
            parent[pj]=pi;
        }
        else if(rank[pj]>rank[pi])
        parent[pi]=pj;
        else
        {
            parent[pj]=pi;
            rank[pi]++;
        }
        group--;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
       int v=isConnected.size();
    parent.resize(v);
       rank.resize(v,0);
       group=v;
       for(int i=0;i<v;i++)
       parent[i]=i;
       for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (isConnected[i][j] == 1 && i != j) { 
                    union1(i, j);
                }
            }
        }
       return group;
    }
};