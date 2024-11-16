class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
      int n = nums.size(), i=0, j=0, val = nums[0];
      vector<int>ans;
      while(j<n && i< n - k + 1){
            while(j<n && j - i + 1 <= k && nums[j] == val){
                j++, val++;
            }
            if(j - i == k){
                ans.push_back(val-1);
                i++;
            }
            else{
                while(i < n - k + 1 && i < j){
                    ans.push_back(-1);
                    i++;
                }
                val = nums[j];
            }
      }  
      return ans;
    }
};
