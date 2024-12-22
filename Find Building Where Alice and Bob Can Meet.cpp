class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<vector<vector<int>>>  qs(heights.size());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> res(queries.size(), -1);

        for(int q = 0; q< queries.size() ; q++){
            int a = queries[q][0], b = queries[q][1];
            int mini = min(a,b), maxi = max(a,b);

            if(mini == maxi || heights[maxi] > heights[mini]) res[q] = maxi;
            else{
                qs[maxi].push_back({max(heights[mini], heights[maxi]),q});
            }
        }
        for(int i = 0; i<heights.size() ; i++){
            while(!pq.empty() && pq.top()[0] < heights[i]){
                res[pq.top()[1]] = i;
                pq.pop();
            }
            for(auto ele: qs[i]){
                pq.push(ele);
            }
        }
        return res;
    }
};
