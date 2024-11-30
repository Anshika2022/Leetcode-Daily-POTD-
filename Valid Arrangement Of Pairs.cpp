class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        map<int,vector<int>>G;
        map<int, int>outdegree;

        for(auto e : pairs){
            int u = e[0], v = e[1];
            G[u].push_back(v);
            outdegree[u]++;
            outdegree[v]--;
        }
        int u = outdegree.begin()->first;
        for(auto &[v,d] : outdegree){
            if(d == 1){
                u = v;
                break;
            }
        }
        vector<int>curr_path, eulerian;
        curr_path.push_back(u);

        while(!curr_path.empty()){
            u = curr_path.back();
            if(G[u].empty()){
                eulerian.push_back(u);
                curr_path.pop_back();
            }
            else{
                int v = G[u].back();
                curr_path.push_back(v);
                G[u].pop_back();
            }
        }
        vector<vector<int>>ans;
        for(int i = eulerian.size()-2; i >= 0; i--){
            ans.push_back({eulerian[i+1], eulerian[i]});
        }
        return ans;
    }
};
