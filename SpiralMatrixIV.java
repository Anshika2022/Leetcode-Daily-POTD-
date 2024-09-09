/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int[][] spiralMatrix(int m, int n, ListNode head) {
        boolean row = true, rf = true, cf = false;
        int rt = 0, rb = m-1, cl = 0, cr = n-1;
        int[][] ans = new int[m][n];
        for(int[]i:ans){
            Arrays.fill(i, -1);
        }
        while(head!=null){
            if(row){
                if(rf){
                    for(int i=cl; i<=cr; i++){
                        if(head==null) break;
                        ans[rt][i] = head.val;
                        head = head.next;
                    }
                  rt+=1;
                } else {
                    for(int i =cr; i>=cl; i--){
                        if(head==null) break;
                        ans[rb][i] = head.val;
                        head = head.next;
                    }
                    rb-=1;
                }
               rf = !rf;
            } else {
                if(cf){
                    for(int i =rb; i>=rt; i--){
                        if(head==null) break;
                        ans[i][cl] = head.val;
                        head = head.next;
                    }
                cl+=1;
            } else {
                    for(int i=rt; i<=rb; i++){
                        if(head==null) break;
                        ans[i][cr] = head.val;
                        head = head.next;
                    }
                    cr-=1;
                }
                cf = !cf;
            }
            row = !row;
        }
        return ans;
    }
}
