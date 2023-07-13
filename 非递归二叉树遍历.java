import java.util.Stack;

import org.junit.Test;

public class 非递归二叉树遍历 {


    @Test
    public void test(){

    }

    class TreeNode {
        TreeNode left;
        TreeNode right;
        int val;

        TreeNode(int val) {
            this.val = val;
        }

    }
    /**
     * 先序遍历
     * @param node
     */
    public void traversal(TreeNode node){

        Stack<TreeNode> stack = new Stack<>();
        if(node == null) return;
        stack.push(node);
        while(!stack.isEmpty()){
            TreeNode thenode = stack.pop();
            if(thenode == null) continue;
            System.out.println(thenode.val);
            stack.push(thenode.right);
            stack.push(thenode.left);

            
        }


    }

    /**
     * 中序遍历
     * @param root
     */
    public void traversal2(TreeNode root){
        Stack<TreeNode> s = new Stack<TreeNode>();
        TreeNode p = root;
        while(p != null || !s.empty()) {
            while (p != null) {
               s.push(p);
               p = p.left;
            }
            p = s.pop();
            System.out.print(p.val+" ");
            p = p.right;
            
       }
  }

    /**
     * 后序遍历
     * @param node
     */
    public void traversal3(TreeNode node){

        

    }
    
}
