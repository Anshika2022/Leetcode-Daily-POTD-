class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size(), i = 0, j = 0;
        vector<int>max_window(n);
        vector<bool>ans(q,true);
        while(j<n-1){
            while(j < n-1 && (nums[j] % 2 != nums[j+1] % 2)){
                max_window[i] = j;
                j++;
            }
            while(i <= j){
                max_window[i] =j;
                i++;
            }
            j++;
        }
        while(i < min(n-1,j)){
            max_window[i] = j;
            i++;
        }
        for(int i = 0; i < q; i++){
            int u = queries[i][0], v = queries[i][1];
            if(max_window[u] < v){
                ans[i] = false;
            }
        }
        return ans;
    }
};
