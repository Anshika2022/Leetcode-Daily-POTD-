class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][1] > 1 && grid[1][0] > 1){
            return -1;
        }
        vector<vector<int>>time(n,vector<int>(m,INT_MAX));
        vector<vector<int>>dir = {{0,-1},{0,1},{1,0},{-1,0}};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        time[0][0] =0;
        pq.push({0, 0, 0});
        while(!pq.empty()){
            int t = pq.top()[0], x = pq.top()[1], y=pq.top()[2]; pq.pop();
            for(int i = 0; i<4; i++){
                int dx = x + dir[i][0], dy = y + dir[i][1];

                if(dx<0 || dy <0 || dx == n || dy == m){
                    continue;
                }

                int wait = ((grid[dx][dy] - t) % 2 == 0) ? 1 : 0;
                int next_time = max(grid[dx][dy] + wait, t+1);
                
                if(time[dx][dy] > next_time){
                    time[dx][dy] = next_time;
                    pq.push({next_time, dx, dy});

                }
            }
        }
        return time[n-1][m-1] == INT_MAX ? -1 : time[n-1][m-1];
    }
};
