class Solution {
     bool canAssign(int mid,int n,vector<int>& quantities){
        int count = 0;
        for(int i=0;i<quantities.size();++i)
            count += ceil((double)quantities[i]/mid);
        
        return count<=n;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m=quantities.size();

        int low = 1;
        int high = *max_element(quantities.begin(),quantities.end());
        int mid;
        int ans=INT_MAX;
        
        while(low<=high){
            mid = low+(high-low)/2;

            if(canAssign(mid,n,quantities)){
                ans = min(ans,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
