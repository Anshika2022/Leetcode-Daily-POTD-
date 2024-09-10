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
    public ListNode insertGreatestCommonDivisors(ListNode head) {
        ListNode prev = head, curr = head.next;
        while(curr!=null){
            int gcd = gcd(prev.val, curr.val);
            ListNode node = new ListNode(gcd);
            prev.next = node;
            curr.next = curr;
            prev= curr;
            curr = curr.next;
        }

        return head;
    }
    private int gcd(int a, int b){
        if(a==b) return a;
        if(a>b) return gcd(a-b, b);
        return gcd(a, b-a); 
    }
}
