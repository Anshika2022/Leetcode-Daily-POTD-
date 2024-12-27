class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        int result = 0;

        for(int j = 1; j < n; j++) {
            int max_val = 0;
            for(int i = j-1; i >= 0; i--) {
                max_val = max(max_val, values[i]+i);
            }

            result = max(result, max_val + values[j]-j);
        }

        return result;
    }
};
