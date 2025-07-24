class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int>v1,v2;
        string temp="";
        for(char ch:version1)
        {
            if(ch=='.')
            {
                v1.push_back(stoi(temp));
                temp="";
            }
            else
            {
                temp+=ch;
            }
        }
        v1.push_back(stoi(temp));
        temp="";
        for(char ch:version2)
        {
            if(ch=='.')
            {
                v2.push_back(stoi(temp));
                temp="";
            }
            else
            {
                temp+=ch;
            }
        }
        v2.push_back(stoi(temp));
        int len=max(v1.size(),v2.size());
        for(int i=0;i<len;i++)
        {
            int num1=i<v1.size()?v1[i]:0;
            int num2=i<v2.size()?v2[i]:0;
            if(num1<num2)
            return -1;
            else if(num2<num1)
            return 1;
        }
        return 0;
    }
};