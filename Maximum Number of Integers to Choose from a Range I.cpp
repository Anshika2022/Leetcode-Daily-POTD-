class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<bool>mark(n+1,false);
        for(auto c : banned){
            if(c <= n){
                mark[c] = true;
            }
        }
        int ans = 0, sum = 0;
        for(int i = 1; i<= n; i++){
            if(!mark[i] && sum + i <= maxSum){
                sum += i;
                ans++;
            }
        }
        return ans;
    }
};
