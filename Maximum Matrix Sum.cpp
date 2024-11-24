class Solution {
public:
    #define ll long long
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), negcnt = 0; ll ans =0, minval = INT_MAX;
        for(int i = 0; i<n; i++){
            for(int j=0; j<n; j++){
                ans += abs(matrix[i][j]);
                if(matrix[i][j] < 0){
                    negcnt++;
                }
                minval = min(minval, (ll)abs(matrix[i][j]));
            }
        }
        return(negcnt % 2 ? ans - 2 *minval : ans);
    }
};
