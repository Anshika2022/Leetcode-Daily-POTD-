class Solution {
public:
    #define ll long long
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), i=0, j=0, c=0, maxval = *max_element(nums.begin(), nums.end()); ll ans =0, currsum =0;
        vector<int>freq(maxval+1, 0);

        while(j<k){
            currsum += nums[j];
            if(!freq[nums[j]]){
                c++;
            }
            freq[nums[j]]++;
            j++;
        }
        while(j<n){
            if(c==k){
                ans = max(ans, currsum);
            }
            currsum -= nums[i]; freq[nums[i]]--;
            if(!freq[nums[i]]){
                c--;
            }
            currsum += nums[j];
            if(!freq[nums[j]]){
                c++;
            }
            freq[nums[j]]++;
            i++, j++;
        }
        if(c == k){
            ans = max(ans, currsum);
        }
        return ans;
    }
};
