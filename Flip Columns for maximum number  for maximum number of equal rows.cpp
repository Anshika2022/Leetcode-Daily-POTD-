class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
      int n = matrix.size(), m = matrix[0].size(), ans = 0;
      map<string,int>cnt;
      for(int i =0; i<n ; i++){
        string curr = "", comp = "";
        for(int j = 0; j<m; j++){
            if(matrix[i][j]){
                curr += '1';
                comp += '0';
            }
            else{
                curr += '0';
                comp += '1';
            }
        }
        cnt[curr]++;
        ans = max(ans, cnt[curr] + cnt[comp]);
      }
      return ans;
    }
};
