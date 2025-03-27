class Solution {
    public int minimumIndex(List<Integer> nums) {
        int n = nums.size();
        Map<Integer, Integer> freqMap = new HashMap<>();

        // Step 1: Find the dominant element using a frequency map
        int dominantElement = nums.get(0);
        int maxFreq = 0;
        for (int num : nums) {
            int freq = freqMap.getOrDefault(num, 0) + 1;
            freqMap.put(num, freq);
            if (freq > maxFreq) {
                maxFreq = freq;
                dominantElement = num;
            }
        }

        // Step 2: Initialize counters for the dominant element
        int leftCount = 0;
        int rightCount = maxFreq;

        // Step 3: Iterate to find the minimum valid split index
        for (int i = 0; i < n - 1; ++i) {
            if (nums.get(i) == dominantElement) {
                leftCount++;
                rightCount--;
            }
            if (leftCount * 2 > (i + 1) && rightCount * 2 > (n - i - 1)) {
                return i;
            }
        }
        return -1;
    }
}
