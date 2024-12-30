class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int maxi=0;
        int l=0;
        unordered_set<int>st;
        for(int r=0;r<str.length();r++){
            if(st.find(str[r])!=st.end()){
                while(l<r && st.find(str[r])!=st.end()){
                    st.erase(str[l]);
                    l++;
                
                }
            }
            
                st.insert(str[r]);
                maxi=max(maxi,r-l+1);
        }
        return maxi;
    }
};