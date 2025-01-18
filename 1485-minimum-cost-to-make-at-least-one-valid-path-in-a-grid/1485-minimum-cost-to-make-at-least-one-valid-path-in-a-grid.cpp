class Solution {
public:
bool isValid(int& x,int& y,int& m,int& n){
        return (x>=0 and x<m and y>=0 and y<n);
    }
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<bool>>visited (m,vector<bool>(n));
        vector<int> dx = {0,0,1,-1};//RLDU
        vector<int> dy = {1,-1,0,0};
        pq.push({0,{0,0}});
        while(!pq.empty())
        {
             auto curr = pq.top();
            pq.pop();

            int cost = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;

            if(visited[x][y]==true) //Already Processed
                continue;
            if(x==m-1 and y==n-1)   //Reached Destination
                return cost;
            visited[x][y] = true;
            for(int i=0;i<4;++i){//RLDU
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(isValid(newX,newY,m,n) and !visited[newX][newY]){
                    int new_cost = cost;
                    new_cost += (i+1)==grid[x][y]?0:1;
                    pq.push({new_cost, {newX, newY}});
                }
            }
        }
        return 0;

    }
};