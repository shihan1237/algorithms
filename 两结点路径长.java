package com;

import java.util.LinkedList;

import org.junit.Test;

public class 两结点路径长 {
    @Test
    public void test() {
        TreeNode node1 = new TreeNode(1);
        node1.left = new TreeNode(2);
        node1.right = new TreeNode(3);
        node1.left.left = new TreeNode(4);
        node1.left.right = new TreeNode(5);
        TreeNode parent = getPublicParent(node1, node1.left.left, node1.right);
        int a = getDistance2(parent, node1.left.left);
        int b = getDistance2(parent, node1.right);
        System.out.println(getDistance2(parent, node1.left.left) + getDistance2(parent, node1.right));
    }

    class TreeNode {
        TreeNode left;
        TreeNode right;
        int val;

        TreeNode(int val) {
            this.val = val;
        }

    }

    // 求两结点的最短路径，首先求公共父节点，然后求两个路径长度
    public TreeNode getPublicParent(TreeNode root, TreeNode node1, TreeNode node2) {
        if (root == null || root == node1 || root == node2)
            return root;
        TreeNode return1 = getPublicParent(root.left, node1, node2);
        TreeNode return2 = getPublicParent(root.right, node1, node2);
        if (return1 != null && return2 != null)
            return root;
        else if (return1 != null)
            return return1;
        else if (return2 != null)
            return return2;
        else
            return null;

    }

    public int getDistance(TreeNode root, TreeNode node) {
        LinkedList<TreeNode> list = new LinkedList();
        list.offer(root);
        int res = 0;
        while (list.size() > 0) {
            int size = list.size();
            for (int i = 0; i < size; i++) {
                TreeNode theNode = list.poll();
                if (theNode == node)
                    return res;
                list.offer(theNode.left);
                list.offer(theNode.right);

            }
            res++;

        }
        return -1;
    }
    
    // public int getDistance2(TreeNode root, TreeNode node) {
    //     TreeNode curNode = root;
    //     dfs(root, node, curNode, 0);
    //     int asd = res;
    //     res = -1;
    //     return asd;
    // }

    // int res = -1;

    // public void dfs(TreeNode root, TreeNode node, TreeNode curNode, int cur) {
    //     if (curNode == null||res!=-1)
    //         return;
    //     if (node == curNode) {
    //         res = cur;
    //         return;
    //     }
    //     dfs(root, node, curNode.left, cur + 1);
    //     dfs(root,node, curNode.right, cur + 1);

    // }

    public int getDistance2(TreeNode root, TreeNode node) {
        TreeNode curNode = root;
        int res = dfs(root, node, curNode, 0);
        return res;
    }

    public int dfs(TreeNode root, TreeNode node, TreeNode curNode, int cur) {
        if (curNode == null)
            return -1;
        if (node == curNode) {
            return cur;
        }
        int a = dfs(root, node, curNode.left, cur + 1);
        int b = dfs(root,node, curNode.right, cur + 1);
        if(a==-1) return b;
        else return a;

    }

}
