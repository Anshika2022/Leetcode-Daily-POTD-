class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n= arr.size(), ans = INT_MAX, left =0, right=n-1, i=0, j=0;
        while(left+1<n && arr[left] <= arr[left+1]){
            left++;
        }
        if(left == n-1){
            return 0;
        }
        while(right-1 >= 0 && arr[right-1] <= arr[right]){
            right--;
        }
        ans = min(right, n - left - 1);
        j=right;
        while(i <= left && j<n){
            if(arr[i] <= arr[j]){
                ans = min(ans, j-i-1);
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};
