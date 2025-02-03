class Solution {
    public int longestMonotonicSubarray(int[] nums) {
     if (nums.length == 0) return 0;

        int maxLength = 1;
        int incLength = 1, decLength = 1;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > nums[i - 1]) {
                incLength++;
                decLength = 1;
            } else if (nums[i] < nums[i - 1]) {
                decLength++;
                incLength = 1;
            } else {
                incLength = 1;
                decLength = 1;
            }
            maxLength = Math.max(maxLength, Math.max(incLength, decLength));
        }

        return maxLength;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {1, 4, 3, 3, 2};
        System.out.println(solution.longestMonotonicSubarray(nums));   
    }
}
