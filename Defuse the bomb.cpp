class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int>ans(n,0);

        if(k==0){
            return ans;
        }
        else if(k<0){
            k = abs(k); int i = n-k, j = n-k, sum = 0, c= 0;
            while(j<n){
                sum += code[j];
                j++;
            }
            while(c<n){
                ans[c] = sum;
                sum -= code[i%n];
                sum += code[j%n];
                i++, j++, c++;
            }
            return ans;
        }
        else{
            int i = 1, j = 1, sum =0, c=0;
            while(j <= k){
                sum += code[j];
                j++;
            }
            while(c< n){
                ans[c] = sum;
                sum -= code[i % n];
                sum += code[j % n];
                i++, j++, c++;
            }
        }
        return ans;
    }
};
