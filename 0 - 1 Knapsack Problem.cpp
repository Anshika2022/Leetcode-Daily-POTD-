class Solution {
  public:
    int dp[1001][1001];
    int solve(int W, vector<int> &val, vector<int> &wt,int i){
        //base case
        if(i==wt.size()) return 0;
        //recursive case
        int pick=0;
        if(dp[i][W]!=-1) return dp[i][W];
        if(W>= wt[i])
        pick=val[i]+solve(W-wt[i],val,wt,i+1);
        int nopick=solve(W,val,wt,i+1);
        
        return dp[i][W] = max(pick,nopick);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt){
        memset(dp,-1,sizeof(dp));
        memset(dp,-1,sizeof(dp));
        return solve(W,val,wt,0);
        
    }
};
