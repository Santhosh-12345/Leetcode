class Solution {
public:
    string smallestNumber(string pattern) {
        stack<int>st;
        int num=1;
        string result="";
        for(int i=0;i<=pattern.size();i++)
        {
            st.push(num);
            num++;
            if(i==pattern.size() || pattern[i]=='I')
            {
                while(!st.empty())
                {
                    result+=st.top()+'0';
                    st.pop();
                }
            }
        }
        return result;
    }
};