class Solution {
public:
    bool isValid(int num,string sq,int ind,int sum)
    {
        if(ind==sq.size())
        return sum==num;
        int a=0;
        for(int i=ind;i<sq.size();i++)
        {
            a=a*10+(sq[i]-'0');
            if(isValid(num,sq,i+1,sum+a))
            return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            string square=to_string(i*i);
            if(isValid(i,square,0,0))
            sum+=i*i;
        }
        return sum;
    }
};