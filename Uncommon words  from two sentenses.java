class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
        String[] str1 = s1.split(" ");
        String[] str2 = s2.split(" ");
        HashMap<String,Integer> hm  = new HashMap<>();
        for(String s : str1){
            hm.put(s,hm.getOrDefault(s,0)+1);
        }
        for(String s : str2){
            hm.put(s,hm.getOrDefault(s,0)+1);
        }
        int count = 0;
        for(Map.Entry<String,Integer> e : hm.entrySet()){
            if(e.getValue() == 1){
                count++;
            }
        }
        String[] arr = new String[count];
        int k =0;
        for(Map.Entry<String,Integer> e : hm.entrySet()){
            if(e.getValue() == 1){
                arr[k] = e.getKey();
                k++;
            }
        }
        return arr;
    }
}
