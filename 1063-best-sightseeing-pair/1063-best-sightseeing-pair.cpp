class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxi=INT_MIN;
        int m=values[0];
        for(int i=1;i<values.size();i++)
        {
            maxi=max(maxi,m+values[i]-i);
            m=max(m,values[i]+i);
        }
        return maxi;
    }
};