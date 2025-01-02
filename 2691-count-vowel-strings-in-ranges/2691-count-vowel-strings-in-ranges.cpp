class Solution {
public:
    bool isValid(string str,unordered_set<char>&st)
    {
        if(str.size()==1 && st.find(str[0])!=st.end())
        return true;
        else if(st.find(str[0])!=st.end() && st.find(str[str.size()-1])!=st.end())
        return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>prefixSum(n+1,0);
        
        unordered_set<char>st={'a','e','i','o','u'};
        for(int i=0;i<n;i++)
        {
            prefixSum[i + 1] = prefixSum[i] + (isValid(words[i], st) ? 1 : 0); 
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            ans.push_back(prefixSum[r+1]-prefixSum[l]);
        }
        return ans;
    }
};