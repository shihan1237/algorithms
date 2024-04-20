import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import org.junit.Test;

public class 微软面试算法题 {

    @Test
    public void test() {
        List<List<Integer>> graph = new ArrayList();
        graph.add(new ArrayList(){{
            add(2);
            add(1);
        }});
        graph.add(new ArrayList(){{
            add(4);
            add(3);
        }});
        graph.add(new ArrayList());
        graph.add(new ArrayList());
        graph.add(new ArrayList());
        graph.add(new ArrayList(){{
            add(1);
            add(0);
        }});
        List<Integer> input = new ArrayList();
        input.add(1);
        input.add(3);
        input.add(4);
        input.add(5);
        input.add(0);
        input.add(2);
        List<Integer> theRes = sort(input, graph);
        for(Integer i: theRes){
            System.out.println(i);
        }
    }

    Set<Integer> set;
    List<Integer> res;
    //根据依赖关系，输出正确的顺序。注：在满足依赖关系的同时，还需要尽可能地正序排序
    //0->1,2  1->3,4  5->0,1  // 2,3,1  3,2
    public List<Integer> sort(List<Integer> input, List<List<Integer>> graph) {
        res = new ArrayList();
        set = new HashSet();
        for (Integer s : input) {
            set.add(s);
        }
        for(int i = 0; i<input.size();i++){
            dfs(graph, input.get(i));
        }
        

        return res;

    }

    public void dfs(List<List<Integer>> graph, Integer cur) {
        if (graph.get(cur).size() == 0) {

            // if (set.contains(cur)&&!res.contains(cur))
            if (!res.contains(cur))
                res.add(cur);
            return;
        }

        for (Integer i : graph.get(cur)) {
            dfs(graph, i);
        }
        // if (set.contains(cur)&&!res.contains(cur))
        if (!res.contains(cur))
                res.add(cur);

    }

}
