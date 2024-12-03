class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size(), m = spaces.size(), i = 0, j = 0; string ans = "";
        while(i<n){
            if(j<m  && spaces[j] == i){
                ans += " ";
                j++;
            }
            else{
                ans += s[i];
                i++;
            }
        }
        return ans;
    }
};
