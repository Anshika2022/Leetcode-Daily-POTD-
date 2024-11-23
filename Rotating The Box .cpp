class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        for(int i = 0; i<n; i++){
            int start = m-1, end = m-1;
            while(start >= 0 && end >= 0){
                start = min(start, end);
                if(box[i][start] == '*'){
                    end = start - 1;
                    start--;
                }
                else if(box[i][start] == '#'){
                    if(box[i][end] == '.'){
                        swap(box[i][start], box[i][end]);
                        start--;
                    }
                    end--;
                }
                else{
                    start--;
                }
            }
        }
        vector<vector<char>>ans(m,vector<char>(n,'.')); int idx =0;
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j<m; j++){
                ans[j][idx] = box[i][j];
            }
            idx++;
        }
        return ans;
    }
};
