class Solution {
  public:
  void inorder(Node* root,vector<int>&temp){
        if(!root)return ;
        inorder(root->left,temp);
        temp.push_back(root->data);
        inorder(root->right,temp);
    }
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        // Your code here
        if(!root->left && !root->right) return true;
        vector<int>temp;
        inorder(root,temp);
        for(int i=0;i<temp.size()-2;i++){
            if(temp[i]>temp[i+1]) return false;
        }
        return true;
        
    }
};
