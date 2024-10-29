class Solution {
    public int maxMoves(int[][] grid) {
       int n=grid.length, m=grid[0].length, max=0;
       int[][] dp = new int[n][m];
       for(int[] arr: dp) Arrays.fill(arr, -1);
       for(int i=0; i<n; i++){
        max=Math.max(max, getMax(i, 0, grid, dp));
       } 
       return max;
    }
    private int getMax(int i, int j, int[][] grid, int[][] dp){
        int n=grid.length, m=grid[0].length;
        if(i==n && j==m) return 0;

        if(dp[i][j] !=-1) return dp[i][j];
        int max=0;
        if(i-1>=0 && j+1<m && grid[i-1][j+1]>grid[i][j]){
            max = 1+getMax(i-1, j+1, grid, dp);
        }
        if(j+1<m && grid[i][j+1]>grid[i][j]){
            max = Math.max(max, 1+getMax(i, j+1, grid, dp));
        }
        if(i+1<n && j+1<m && grid[i+1][j+1]>grid[i][j]){
            max = Math.max(max, 1+getMax(i+1, j+1, grid, dp));
        }
        return dp[i][j]=max;
    }
}
