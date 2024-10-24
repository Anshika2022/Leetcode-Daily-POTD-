class Solution {
    public boolean flipEquiv(TreeNode root1, TreeNode root2) {
        //base cases
        if(root1 == null && root2==null){
            return true;
        }
        if(root1 == null || root2==null){
            return false;
        }
        if(root1.val!=root2.val){
            return false;
        }
        //orignal
        boolean isSame = flipEquiv(root1.left, root2.left) && flipEquiv(root1.right, root2.right);
        if(isSame){
            return true;
        }
        //flip
        return flipEquiv(root1.left, root2.right) && flipEquiv(root1.right, root2.left);
    }
}
