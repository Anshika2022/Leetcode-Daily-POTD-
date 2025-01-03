class Solution {
    public int waysToSplitArray(int[] nums) {
       long right = 0;
        long left = 0;
        for(int num : nums){
            right += num;
        }
        int n = nums.length;
        int count=0;
        for(int i=0;i<n-1;i++){
            left += nums[i];
            right -= nums[i];
            if(left >= right){
                count++;
            }
        }
        return count;
    }
}