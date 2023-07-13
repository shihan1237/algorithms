import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import org.junit.Test;
//微派面试手撕算法: 给出所有相加为target的集合的正序排序，不能重复
public class 微派面试算法题 {

    @Test
    public void test(){

        int[] input = new int[]{2,3,4,5,6,1,2,3};
        int target = 10;
        System.out.println(fun(input, target));

    }
    List<List<Integer>> res;
    Set<List<Integer>> tmp;
    public List<List<Integer>> fun(int[] input, int target){
        tmp = new HashSet<>();
        res = new ArrayList<>();
        boolean[] isSelected = new boolean[input.length];
        for(int i = 0; i<input.length;i++){
            List<Integer> newList = new ArrayList();
            dfs(i, input, target, newList, 0, isSelected);
        }
        return res;
        
    }

    public void dfs(int i, int[] input, int target, List<Integer> curList, int sum, boolean[] isSelected){

        if(sum > target||isSelected[i]==true) return;
        else if(sum == target){
            // res.add(curList);
            Collections.sort(curList);
            add(res, curList);
            return;
        }
        List<Integer> newList = new ArrayList();
        newList.addAll(curList);
        newList.add(input[i]);
        isSelected[i]=true;
        for(int j = 0; j<input.length;j++){
            dfs(j, input, target, newList, sum+input[i], isSelected);
        }
        isSelected[i]=false;
    }
    //去重
    public void add(List<List<Integer>> res, List<Integer> curList){
        String s1 = curList.toString();
        // for(List<Integer> list: res){
            //法一：
            // String s = list.toString();
            // if(s.equals(s1)) return;
            //法二：
            // if(list.equals(curList)) return;
            
            
        // }
        // res.add(curList);
        //法三：
            tmp.add(curList);
            res.clear();
            res.addAll(tmp);
        

    }
    
}
