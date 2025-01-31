import java.util.*;

public class Solution {
    private static final int[] DIRS = {0, 1, 0, -1, 0};

    public int largestIsland(int[][] grid) {
        int n = grid.length;
        Map<Integer, Integer> islandSizes = new HashMap<>();
        int islandId = 2; // Start IDs from 2 since grid contains 0s and 1s
        int maxIslandSize = 0;

        // Step 1: Identify and label all islands with unique IDs
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(grid, i, j, islandId);
                    islandSizes.put(islandId, size);
                    maxIslandSize = Math.max(maxIslandSize, size);
                    islandId++;
                }
            }
        }

        // Step 2: Evaluate potential expansion by flipping one 0 to 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    Set<Integer> neighboringIslands = new HashSet<>();
                    int potentialSize = 1; // Start with size 1 for the flipped cell

                    for (int d = 0; d < 4; d++) {
                        int ni = i + DIRS[d];
                        int nj = j + DIRS[d + 1];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] > 1) {
                            int id = grid[ni][nj];
                            if (neighboringIslands.add(id)) {
                                potentialSize += islandSizes.get(id);
                            }
                        }
                    }

                    maxIslandSize = Math.max(maxIslandSize, potentialSize);
                }
            }
        }

        // Step 3: Handle the edge case where there's no water cell
        return maxIslandSize == 0 ? n * n : maxIslandSize;
    }

    private int dfs(int[][] grid, int i, int j, int id) {
        int n = grid.length;
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) {
            return 0;
        }
        grid[i][j] = id;
        int size = 1;
        for (int d = 0; d < 4; d++) {
            size += dfs(grid, i + DIRS[d], j + DIRS[d + 1], id);
        }
        return size;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] grid = {
            {1, 0, 1, 1, 0},
            {1, 0, 0, 1, 0},
            {0, 1, 1, 0, 1},
            {1, 0, 1, 0, 1},
            {0, 1, 0, 1, 0}
        };
        System.out.println("Largest island size: " + sol.largestIsland(grid));
    }
}
