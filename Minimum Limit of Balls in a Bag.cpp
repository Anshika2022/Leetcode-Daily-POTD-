class Solution {
public:
#define ll long long
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size(), start = 1, end = *max_element(nums.begin(), nums.end()), mid , ans =0;
        while(start <= end){
            mid = start +  (end - start) / 2;
            ll oper = 0;
            for(int i =0; i<n; i++){
                if(nums[i] % mid == 0){
                    oper += (nums[i] / mid - 1);
                }
                else{
                    oper += (nums[i] / mid );
                }
            }
            if(oper <= maxOperations){
                ans = mid;
               end = mid - 1;
            }
            else{
                start = mid +1;
            }
        }
        return ans;
    }
};
