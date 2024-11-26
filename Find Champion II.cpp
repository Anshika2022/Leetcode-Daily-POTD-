class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n,0);
        for(auto e : edges){
            int v = e[1]; //u -> v
            indegree[v]++;
        }
        int ans = -1;

        for(int u = 0; u<n; u++){
            if(indegree[u] == 0){
                if(ans == -1){
                    ans = u;
                }
                else{
                    return -1;
                }
            }
        }
        return ans;
    }
};
