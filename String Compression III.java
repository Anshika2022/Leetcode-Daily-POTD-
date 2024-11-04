class Solution {
    public String compressedString(String word) {
        int count = 0;
        char curr ='0';
        StringBuilder sb = new StringBuilder();
        for(char c: word.toCharArray()){
            if(count<9 && c==curr){
                count+=1;
            }else{
                if(count>0){
                    sb.append(count);
                    sb.append(curr);
                }
                curr = c;
                count =1;
            }
        }
        sb.append(count);
        sb.append(curr);
        return sb.toString();
    }
}
