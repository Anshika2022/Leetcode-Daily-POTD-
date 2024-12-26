class Solution {
public:
int solve(vector<int>& nums, int &target, int i, int sum, unordered_map<string, int>& memo) {
        if (i == nums.size()) {
            return sum == target ? 1 : 0;
        }

        // Create a unique key for the current state
        string key = to_string(i) + "," + to_string(sum);

        // Check if the result is already computed
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        // Compute the result recursively
        int plus = solve(nums, target, i + 1, sum + nums[i], memo);
        int minus = solve(nums, target, i + 1, sum - nums[i], memo);

        // Store the result in the memo
        memo[key] = plus + minus;

        return memo[key];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> memo;
        return solve(nums, target, 0, 0, memo);
    }
};
