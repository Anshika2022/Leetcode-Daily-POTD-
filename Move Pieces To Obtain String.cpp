class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size(), i = n-1, j = n-1;//Starting from back

        while(i >= 0 && j >= 0 ){
            while(i >= 0 && start[i] == '_'){
                i--;
            }
            while(j >= 0 && target[j] == '_'){
                j--;
            }
            if(i<0 || j<0){
                continue;
            }
            if(start[i] != target[j]){
                return false;
            }
            else{
                if(start[i] == 'L' && i<j){
                    return false;
                }
                else if(start[i] == 'R' && i>j){
                    return false;
                }
                else{
                    i--, j--;
                }
            }
        }
        while(i>=0 && start[i] == '_'){
            i--;
        }
        while(j >= 0 && target[j] == '_'){
            j--;
        }
        return i < 0 && j < 0;
    }
};
