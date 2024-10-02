import java.util.*;

class Solution {
    public int[] arrayRankTransform(int[] arr) {
        int n = arr.length;  // Get the size of the input array
        
        if (n == 0)          // If the array is empty, return an empty array
            return new int[0];
        
        // Create a TreeSet to store unique elements in sorted order
        TreeSet<Integer> uniqueElements = new TreeSet<>();
        for (int ele : arr)
            uniqueElements.add(ele);
        
        // Create a HashMap to store the rank of each unique element
        HashMap<Integer, Integer> ranks = new HashMap<>();
        int rank = 1;  // Rank starts from 1
        
        // Assign ranks to each unique element in the TreeSet (smallest element gets rank 1)
        for (int ele : uniqueElements)
            ranks.put(ele, rank++);
        
        // Create an array to store the rank transformation of the input array
        int[] ans = new int[n];
        
        // For each element in the input array, find its rank and store it in the result array
        for (int i = 0; i < n; i++)
            ans[i] = ranks.get(arr[i]);
        
        return ans;  // Return the rank-transformed array
    }
}
