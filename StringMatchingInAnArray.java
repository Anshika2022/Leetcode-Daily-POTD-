class Solution {
    public List<String> stringMatching(String[] words) {
       List<String> res = new ArrayList<>();
        int n = words.length;
        for (int i = 0;i < n;i++) {

            for (int j = 0;j < n;j++) {
                if (i == j || words[i].length() > words[j].length()) continue;

                if (words[j].contains(words[i])) {
                    res.add(words[i]);
                    break; 
                }
            }

        }

        return res; 
    }
}
