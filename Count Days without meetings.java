class Solution {
    public int countDays(int days, int[][] meetings) {
        Arrays.sort(meetings,(o1,o2)->o1[0]==o2[0]?o1[1]-o2[1]:o1[0]-o2[0]);

        int ans=0;
        int prev=0;
        for(int meet[]:meetings){
            if(meet[0]>prev)    ans+=meet[0]-prev-1;
            prev = Math.max(prev,meet[1]);
        }
        if(days>prev)   ans += days-prev;
        return ans;
    }
}
