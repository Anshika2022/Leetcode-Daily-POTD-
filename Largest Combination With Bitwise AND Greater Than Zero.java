class Solution {
    public int largestCombination(int[] candidates) {
       int max =0;
       for(int i=0; i<=24; i++){
        int setBits =0;
        for(int c: candidates){
            setBits +=(c>>i)& 1;
        }
        max = Math.max(setBits,max);
       } 
       return max;
    }
}
