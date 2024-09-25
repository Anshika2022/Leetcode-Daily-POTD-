class Solution {
    public int[] sumPrefixScores(String[] words) {
        HashMap<String,Integer> map =new HashMap<>();
        int count[] = new int[words.length]; //res
        for(String word : words){
            StringBuilder sb = new StringBuilder();
            for(int i=0;i<word.length();i++){
                sb.append(word.charAt(i));
                String w = sb.toString();
                map.put(w,map.getOrDefault(w,0)+1);
            }
        }
        int index=0;
        for(String word : words){
            int c=0;
            StringBuilder sb = new StringBuilder();
            for(int i=0;i<word.length();i++){
                sb.append(word.charAt(i));
                String w = sb.toString();
                c += map.get(w);
            }
            count[index] = c;
            index++;
        }
        return count;
    }
}
