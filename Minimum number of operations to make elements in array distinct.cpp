#include <vector>
#include <unordered_set>

class Solution {
public:
    int minimumOperations(std::vector<int>& nums) {
        int operations = 0;

        while (true) {
            std::unordered_set<int> seen(nums.begin(), nums.end());
            if (seen.size() == nums.size()) {
                // All elements are distinct
                break;
            }

            // Perform an operation: remove first 3 elements (or all if fewer)
            int removeCount = std::min(3, static_cast<int>(nums.size()));
            nums.erase(nums.begin(), nums.begin() + removeCount);
            operations++;
        }

        return operations;
    }
};
