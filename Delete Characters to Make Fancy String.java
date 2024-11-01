class Solution {
    public String makeFancyString(String s) {
         if (s.length() <= 2) return s; // A string with 2 or fewer characters is already "fancy".
        
        StringBuilder ans = new StringBuilder();
        ans.append(s.charAt(0)); // Add the first character.
        ans.append(s.charAt(1)); // Add the second character.

        // Iterate from the third character onward.
        for (int i = 2; i < s.length(); i++) {
            // Check if the current character forms three consecutive characters with the last two.
            if (!(ans.charAt(ans.length() - 1) == s.charAt(i) && ans.charAt(ans.length() - 2) == s.charAt(i))) {
                ans.append(s.charAt(i));
            }
        }

        return ans.toString();
    }
}
