class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int ans = 0, lastmax = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(auto e : events){
            while(!pq.empty() && pq.top().first < e[0]){
                lastmax = max(lastmax, pq.top().second);
                pq.pop();
            }
            ans = max(ans, lastmax + e[2]);
            pq.push({e[1],e[2]});
        }
        return ans;
    }
};
