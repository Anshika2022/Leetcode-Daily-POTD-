class Solution {
    public List<Integer> lexicalOrder(int n) {
        int i = 1;
        List<Integer> ans = new ArrayList<>();
        for(int j=1; j<=n; j++){
            ans.add(i);
            if(i*10<=n){
                i*=10;
            }else{
                while(i%10==9 || i==n){
                    i/=10;
                }
                i+=1;
            }
        }
        return ans;
    }
}
