class Solution {
public:
    int minAddToMakeValid(string s) {
        int opening = 0;
        int closing = 0;
        for (auto i : s) {
            if (i == ')') {
                if (opening <= 0) {
                    closing++;
                } else {
                    opening--;
                }
            } else {
                opening++;
            }
        }
        return opening + closing;
    }
};
