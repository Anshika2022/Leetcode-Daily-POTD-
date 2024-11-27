class Solution {
public:
    int bfs(vector<vector<int>>& G, int &n){
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<bool>visit(n,false);
        visit[0] = true;
        while(!q.empty()){
            int u = q.front().first, dist = q.front().second; q.pop();
            if(u == n -1){
                return dist;
            }
             for(auto v : G[u]){
                if(!visit[v]){
                    q.push({v, dist+1});
                    visit[v] = true;
                }
             }      
        }
        return INT_MAX;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
       int q = queries.size();
       vector<vector<int>>G(n);
       for(int i = 0; i<n-1; i++){
        G[i].push_back(i+1);
        G[i+1].push_back(i);
       } 
       vector<int>ans(q);
       for(int i = 0; i<q; i++){
           int u = queries[i][0], v = queries[i][1];
           G[u].push_back(v);
           G[v].push_back(u);
           ans[i] = bfs(G,n);
        }
       return ans;
    }
};
