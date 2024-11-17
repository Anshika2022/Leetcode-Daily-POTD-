class Solution {
public:
#define ll long long
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(); ll ans = INT_MAX; ll currsum = 0;
        priority_queue<pair<ll,ll>>pq;
        for(ll i=0; i<n; i++){
            currsum += nums[i];
            if(currsum >= k){
                ans = min(ans, i+1);
            }
            while(!pq.empty() && currsum + pq.top().first >= k){
                ans = min(ans, i - pq.top().second);
                pq.pop();
            }
            pq.push({-currsum, i});


        }
        return ans == INT_MAX ? -1 : ans;
    }
};
