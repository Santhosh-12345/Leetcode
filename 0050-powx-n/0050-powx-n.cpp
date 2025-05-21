class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        long long dummy=n;
        if(n<0)
        {
            dummy=-dummy;
        }
        while(dummy>0)
        {
            if(dummy%2==0)
            {
                x=x*x;
                dummy=dummy/2;
            }
            else{
                ans=ans*x;
                dummy=dummy-1;
            }
        }
        if(n<0)
        return 1/ans;
        return ans;
    }
};