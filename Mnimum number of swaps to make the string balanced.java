class Solution {
    public int minSwaps(String s) {
        Stack<Character> st = new Stack<>();  // Stack to track open brackets '['
        int imbalance_count = 0;  // Variable to count unbalanced closing brackets ']'

        // Loop through the string
        for (char ch : s.toCharArray()) {
            if (ch == '[') {
                st.push('[');  // Push open brackets '[' onto the stack
            } else {
                if (!st.isEmpty()) {
                    st.pop();  // If there's an open bracket in the stack, pop it (i.e., match with ']')
                } else {
                    imbalance_count++;  // If stack is empty, there's an unmatched closing bracket, increase imbalance count
                }
            }
        }

        // Return the minimum swaps required to balance the string
        return (imbalance_count + 1) / 2;
    }
}
