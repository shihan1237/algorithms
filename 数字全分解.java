import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import org.junit.Test;

public class 数字全分解 {

    @Test
    public void test() {
        System.out.println("test");
        List<List<Integer>> res = fun(10);
        for (List<Integer> list : res) {
            System.out.println(list);
        }
    }

    // 给定一个正整数，给出它的所有分解（不重复）
    // 思路，全排列，排序，去重
    Set<List<Integer>> tmp;
    public List<List<Integer>> fun(int input) {
        List<List<Integer>> res = new ArrayList();
        tmp = new HashSet();

        for (int i = input; i > 0; i--) {
            List<Integer> cur = new ArrayList();
            dfs(i, input, res, cur);
        }
        res.addAll(tmp);
        Collections.sort(res, (a,b)->(a.size()-b.size()));
        return res;
    }

    // input:总数， i：当前数
    public void dfs(int i, int input, List<List<Integer>> res, List<Integer> cur) {

        cur.add(i);
        // 总数为input-i，当前数为j
        for (int j = input - i; j > 0; j--) {

            List<Integer> next = new ArrayList();
            next.addAll(cur);
            dfs(j, input - i, res, next);
        }

        if (input == i) {
            cur.sort((a, b) -> a - b);
            addList(res, cur);
        }

    }

    public void addList(List<List<Integer>> res, List<Integer> cur) {
        tmp.add(cur);
        // for (List<Integer> list : res) {

        //     if (list.equals(cur)) {
        //         return;
        //     }
        // }
        // res.add(cur);
    }
}
