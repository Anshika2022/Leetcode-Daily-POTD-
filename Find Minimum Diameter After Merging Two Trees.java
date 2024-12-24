class Solution {
    public int minimumDiameterAfterMerge(int[][] edges1, int[][] edges2) {
        int[] tree1 = findMinHeight(edges1.length+1, edges1);
        int[] tree2 = findMinHeight(edges2.length+1, edges2);
        return Math.max(Math.max(tree1[1], tree2[1]), tree1[0] + tree2[0] + 1);
    }
    public int[] findMinHeight(int n, int[][] edges){
        if(n<=2) return new int[]{n-1, n-1};
        List<List<Integer>> adj = new ArrayList<>();
        for(int i = 0; i<n; i++){
            adj.add(new ArrayList<>());
        }
        int[] degree = new int[n];
        for(int[] edge: edges){
            adj.get(edge[0]).add(edge[1]);
            degree[edge[0]] += 1;
            adj.get(edge[1]).add(edge[0]);
            degree[edge[1]] += 1;
        }
        Queue<Integer> q =new LinkedList<>();
        for(int i =0; i<n; i++){
            if(degree[i] == 1) q.add(i);
        }
        int height = 0, lastLevelSize = 0;
        while(!q.isEmpty()){
            int size = q.size();
            for(int i = 0; i<size; i++){
                int curr = q.remove();
                for(int nbr: adj.get(curr)){
                    degree[nbr] -= 1;
                    if(degree[nbr] == 1) q.add(nbr);
                }
            }
            lastLevelSize = size;
            height += 1;
        }
        height -= 1;
        int diam = 2*height;
        if(lastLevelSize > 1){
            height += 1;
            diam += 1;
        }
        return new int[] {height, diam};
    }
}
