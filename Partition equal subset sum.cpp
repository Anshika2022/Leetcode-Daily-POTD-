#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums)
            totalSum += num;
        
        // If total sum is odd, we can't divide it into two equal subsets
        if (totalSum % 2 != 0)
            return false;

        int target = totalSum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true; // Subset sum of 0 is always possible

        for (int num : nums) {
            for (int i = target; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
            }
        }

        return dp[target];
    }
};
