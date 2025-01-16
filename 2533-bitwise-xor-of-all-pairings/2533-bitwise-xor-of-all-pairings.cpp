class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int xor1=0,xor2=0,xor3=0;
        for(int num: nums1)
        xor1=xor1^num;
        for(int num: nums2)
        xor2=xor2^num;
        if(n%2==1)
        xor3=xor3^xor2;
        if(m%2==1)
        xor3=xor3^xor1;
        return xor3;   
    }
};