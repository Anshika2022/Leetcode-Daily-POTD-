class Solution {
    public boolean check(int[] nums) {
        int count = 0;
        int n = nums.length;
        
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                count++;
            }
        }
        
        // Check the last and first element (for rotation case)
        if (nums[n - 1] > nums[0]) {
            count++;
        }
        
        // If there is at most one break, it's sorted and rotated
        return count <= 1;
    }

    // Test cases
    public static void main(String[] args) {
        Solution sol = new Solution();
        
        int[] arr1 = {3, 4, 5, 1, 2};  // True (rotated sorted)
        int[] arr2 = {2, 1, 3, 4};     // False (not sorted and rotated)
        int[] arr3 = {1, 2, 3, 4, 5};  // True (already sorted)
        
        System.out.println(sol.check(arr1)); // Output: true
        System.out.println(sol.check(arr2)); // Output: false
        System.out.println(sol.check(arr3)); // Output: true
    }
}
