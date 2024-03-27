//Leetcode 234
import java.util.ArrayList;
import java.util.List;

// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public boolean isPalindrome(ListNode head) {
        List<Integer> list = new ArrayList();
        while(head != null) {
            list.add(head.val);
            head = head.next;
        }
        int l = 0, r = list.size()-1;
        while(l < r && list.get(l) == list.get(r)) {
            l++;
            r--;
        } 
        return l >= r;
    }
}
public class palindrome_linked_list {
    public static void main(String[] args) {
        // Creating a linked list: 1 -> 2 -> 2 -> 1
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(2);
        head.next.next.next = new ListNode(1);

        Solution solution = new Solution();
        boolean isPalindrome = solution.isPalindrome(head);

        System.out.println("Is the linked list a palindrome? " + (isPalindrome ? "Yes" : "No"));
    }
}