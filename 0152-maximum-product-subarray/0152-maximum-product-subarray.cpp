class Solution {
public:
    int maxProduct(vector<int>& arr) {
        long long maxProd = arr[0]; 
    long long minProd = arr[0]; 
    long long result = arr[0];  
    int n=arr.size();
    for (int i = 1; i < n; i++) {
        if (arr[i] < 0) 
            swap(maxProd, minProd); // Swap because multiplying by negative flips min/max

        maxProd = max((long long)arr[i], maxProd * arr[i]); // Max product ending at i
        minProd = min((long long)arr[i], minProd * arr[i]); // Min product ending at i

        result = max(result, maxProd); // Update overall max product
    }

    return result;
    }
};