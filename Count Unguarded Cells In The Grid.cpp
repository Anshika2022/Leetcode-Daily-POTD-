class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<vector<bool>>>mark(m,vector<vector<bool>>(n,vector<bool>(2,false)));
        vector<vector<int>>G(m,vector<int>(n,-1));
        for(int i =0; i < walls.size();i++){
            int x = walls[i][0], y= walls[i][1];
            G[x][y]=0;
        }

        for(int i=0; i<guards.size(); i++){
            int x = guards[i][0], y= guards[i][1];
            G[x][y]= 1;
            int dx = x-1, dy = y-1;
            while(dx >= 0 && G[dx][dy] != 0 && !mark[dx][y][0]){
                if(G[dx][y] == -1){
                    G[dx][y] = 2;
                }
                mark[dx][y][0] = true;
                dx--;
            }
            dx=x+1;
            while(dx < m && G[dx][y] != 0 && !mark[dx][y][0]){
                if(G[dx][y]== -1){
                    G[dx][y] =2;
                }
                mark[dx][y][0] = true;
                dx++;
            }
           while(dy >= 0 && G[x][dy] != 0 && !mark[x][dy][1]){
            if(G[x][dy] == -1){
                G[x][dy] = 2;
            }
            mark[x][dy][1] = true;
            dy--;
           } 
           dy = y+1;
           while(dy< n && G[x][dy] != 0 && !mark[x][dy][1]){
            if(G[x][dy] == -1){
                G[x][dy] = 2;
            }
            mark[x][dy][1] = true;
            dy++;
           }
        }
        int ans = 0;
        for(int i=0; i<m ; i++){
            for(int j = 0; j<n; j++){
                if(G[i][j]==-1){
                    ans++;
                }
            }
        }
        return ans;
    }
};
