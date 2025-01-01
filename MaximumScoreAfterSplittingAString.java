class Solution {
    public int maxScore(String s) {
        int ones = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s.charAt(i) == '1') ones++;
        }
        // find max partition
        int res = 0;
        int zeros=0;
        for(int i=0;i<n-1;i++){
            if(s.charAt(i) == '0') zeros++;
            else ones--; 
            res = Math.max(res, ones + zeros);
        }
        return res;
    }
}
