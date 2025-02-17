class Solution {
public:
    
void backtrack(string &tiles,vector<int> &used,unordered_set<string> &st,string current) {
    if(current.size()>0)
    st.insert(current);
    for(int i=0;i<tiles.size();i++)
    {
        if(!used[i])
        {
            used[i]=1;
            backtrack(tiles,used,st,current+tiles[i]);
            used[i]=0;
        }
    }
}
int numTilePossibilities(string tiles) {
    unordered_set<string>st;
    vector<int>used(tiles.size(),0);
    backtrack(tiles,used,st,"");
    return st.size();
}
};