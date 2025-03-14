class Solution {

    // Function to determine if it's possible to distribute candies such that each child gets 'candiesPerChild' candies
    private static boolean canDistribute(int[] candies, long k, int candiesPerChild) {
        long count = 0; // Use long to avoid integer overflow
        for (int candy : candies) {
            count += candy / candiesPerChild;
        }
        return count >= k;
    }

    public int maximumCandies(int[] candies, long k) {
        if (k > 0) { // Ensure k is valid
            int low = 1;
            int high = 0;
            for (int candy : candies) {
                high = Math.max(high, candy);
            }

            int result = 0;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (canDistribute(candies, k, mid)) {
                    result = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            return result;
        }
        return 0; // If k is zero, return 0 (edge case)
    }

    // Example usage
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] candies = {5, 8, 6};
        long k = 3;
        System.out.println("Maximum candies each child can get: " + solution.maximumCandies(candies, k));
    }
}
