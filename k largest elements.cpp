class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
            if(pq.size()>k) pq.pop();
        }
        vector<int>ans(k);
        for(int i=k-1;i>=0;i--){
            ans[i]=pq.top();
            pq.pop();
        }
        return ans;
    }
};
