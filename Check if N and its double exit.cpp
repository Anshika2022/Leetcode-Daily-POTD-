class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size(), mn = *min_element(arr.begin(),arr.end()), mx = *max_element(arr.begin(),arr.end());
        mn = abs(mn); mx = abs(mx);
        vector<int>freq(mx+mn+1, 0);
        for(auto x : arr){
            freq[x+mn]++;
        }
        for(int i = 0; i <= mn +mx; i++){
            if(freq[i] == 0){
               continue;
            }
            int u = i - mn, v = 2 * u + mn;
            if(v >= 0 && v <= mn + mx && freq[v]){
                return true;

            }
        }
        return false;
    }
};
