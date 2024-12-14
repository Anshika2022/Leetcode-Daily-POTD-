class Solution {
    public long continuousSubarrays(int[] nums) {
        TreeMap<Integer,Integer> map = new TreeMap<>();
        int start=0;
        int end=0;
        long count=0;
        int n = nums.length;
        while(end < n){
            map.put(nums[end] , map.getOrDefault(nums[end],0)+1);
            //shrinking
            while(map.lastEntry().getKey() - map.firstEntry().getKey() >2){
                map.put(nums[start] , map.get(nums[start])-1);
                if(map.get(nums[start]) == 0){
                    map.remove(nums[start]);
                }
                start++;
            }
            count += (end - start + 1);
            end++;
        }
        return count;
    }
}
