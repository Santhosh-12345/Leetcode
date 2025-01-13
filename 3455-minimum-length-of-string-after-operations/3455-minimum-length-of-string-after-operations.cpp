class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>mpp;
        for(char c:s)
        mpp[c]++;
        int count=0;
        for(auto it:mpp)
        {
            while(it.second>=3){
            count+=2;
            it.second-=2;
            }
        }
        return s.size()-count;
    }
};
