package com;

import java.util.List;

import org.junit.Test;

public class 双链表反向 {
    @Test
    public void test() {
        ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(2);
        ListNode node3 = new ListNode(3);
        ListNode node4 = new ListNode(4);
        ListNode node5 = new ListNode(5);
        ListNode node6 = new ListNode(6);
        node1.next = node2;
        node2.next = node3;
        node3.next = node4;
        node4.next = node5;
        node5.next = node6;
        ListNode node = reverse(node1, 3);
        while (node != null) {

            System.out.println(node.val);
            node = node.next;
        }

    }
    // ListNode init = new ListNode(0);
    // ListNode pre = init;
    // 双链表反向
    // 思路：预留pre指针，和下一轮指针x。若这一轮不满，则pre指向cur，这一轮满了，把这一轮颠倒，pre变成颠倒后的这一轮的尾指针，指向null
    // public ListNode reverse(ListNode root){
    // init.next = root;
    // ListNode cur = root;
    // while(cur!=null){
    // if(cur.next!=null){
    // ListNode x = cur.next.next;
    // switchNode(cur);
    // cur = x;
    // }
    // else{
    // pre.next =cur;

    // cur = cur.next;
    // }
    // }
    // return init.next;

    // }

    // public void switchNode(ListNode head){
    // ListNode tail = head.next;
    // tail.next = head;
    // pre.next = tail;
    // pre = head;
    // pre.next = null;
    // }

    class ListNode {
        ListNode next;
        int val;

        public ListNode(int val) {
            this.val = val;
        }
    }

    ListNode init = new ListNode(0);
    ListNode pre = init;
    public ListNode reverse(ListNode head, int k) {
        ListNode cur = head;

        asd: while (cur != null) {
            ListNode x = cur;
            for (int i = 0; i < k - 1; i++) {
                x = x.next;
                if (x == null)
                    break asd;
            }
            ListNode y = x.next;
            switchNode(cur, x);
            pre.next = x;
            pre = cur;
            cur = y;

        }
        pre.next = cur;
        return init.next;

    }

    public void switchNode(ListNode left, ListNode right){
        ListNode last, cur, next;
        cur = left;
        next = cur.next;
        while(cur!=right){
            last = cur;
            cur = next;
            next = cur.next;
            cur.next = last;
        }
    }

}
