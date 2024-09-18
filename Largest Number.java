class Solution {
    public String largestNumber(int[] nums) {
        List<String> list = new ArrayList<>();
        for(int i: nums){
            list.add(String.valueOf(i));
        }
        Collections.sort(list, (a,b)->compare(a,b));
        String ans = String.join("",list);
        if(allZeros(ans)) return "0";
        return ans;
    }
    private boolean allZeros(String s){
        for(char c: s.toCharArray()){
            if(c!=0) return false;
        }
        return true;
    }
    private int compare(String a, String b){
        int i=0, j=0;
        while(i<a.length() || j<b.length()){
            if(i==a.length()) i=0;
            if(j==b.length()) j=0;
            if(a.charAt(i)>b.charAt(j)) return -1;
            if(a.charAt(i)<b.charAt(j)) return 1;
            i++;
            j++;
        }
        return 0;
    }
}
