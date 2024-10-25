class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        sort(folder.begin(),folder.end());
        string curr=folder[0];
        ans.push_back(curr);
        for(int i=1;i<folder.size();i++)
        {
            if(folder[i].find(curr+"/")==string::npos || folder[i].find(curr+"/")!=0)
            {
                curr=folder[i];
                ans.push_back(curr);
            }
        }
        return ans;
    }
};
