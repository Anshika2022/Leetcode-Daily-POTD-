class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        int counter =0;
        for(String word : words){
            boolean flag = true;
            for(char c : word.toCharArray()){
                if(allowed.indexOf(c)==-1){
                    flag = false;
                    break;
                }
            }
            if(flag)
               counter ++;
        }
        return counter;
    }
}
