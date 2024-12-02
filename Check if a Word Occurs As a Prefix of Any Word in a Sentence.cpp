class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream val(sentence);
        string nw;
        int ans = 1, m = searchWord.size();

        while(val >> nw){
            int n = nw.size(), i = 0, j = 0;
            while(i<n && j<m && searchWord[j] == nw[i]){
                i++, j++;
            }
            if(j == m){
                return ans;
            }
            ans++;
        }
        return -1;
    }
};
