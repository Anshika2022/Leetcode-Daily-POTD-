class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> st(nums.begin(),nums.end());
        int mini = *st.begin();
        if(k<mini) return st.size();
        if(mini==k) return st.size()-1;
        return -1;
    }
};
