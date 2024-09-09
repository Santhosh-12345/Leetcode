class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       priority_queue<int>max_heap;
       int n=stones.size();
       for(int i=0;i<n;i++)
       max_heap.push(stones[i]);
       while(n>1)
       {
            int first=max_heap.top();
            max_heap.pop();
            int second=max_heap.top();
            max_heap.pop();
            n=n-2;
            if(first-second>0)
            {
                max_heap.push(first-second);
                n=n+1;
            }
       } 
       if(!max_heap.empty())
       return max_heap.top();
       return 0;
    }
};