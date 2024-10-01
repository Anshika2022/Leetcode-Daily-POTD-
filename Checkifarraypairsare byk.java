class Solution {
    public boolean canArrange(int[] arr, int k) {
        Map<Integer,Integer>m =new HashMap<>();
        
        for(Integer x: arr){
            int rem = x%k;
            if(rem<0) rem+=k;
            
            m.put(rem,m.getOrDefault(rem,0)+1);
        }
        
        if(m.containsKey(0) && m.get(0)%2==1)
            return false;
        
        if(m.containsKey(0))
            m.remove(0);
        
        for(Integer x: m.keySet()){
            int rem = x;
            int a = m.getOrDefault(k-rem,0);
            int b = m.get(rem);
            if(a!=b)
                return false;
        }
        return true;
    }
}
