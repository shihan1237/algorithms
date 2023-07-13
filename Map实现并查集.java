import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.junit.Test;

public class Map实现并查集 {
    @Test
    public void test(){
            MergeFind mf = new MergeFind();
            List<List<String>> list = new ArrayList();
            System.out.println();
        }


    class MergeFind{
        Map<String, String> parent;
        int count = 0;
        public MergeFind(){
            parent = new HashMap();
        } 
        public String find(String x){
            if(!parent.containsKey(x)){
                parent.put(x, x);
                count++;
            }
            if(!parent.get(x).equals(x)){
                parent.put(x, find(parent.get(x)));
            }
            return parent.get(x);
        }
        public void merge(String x, String y){
            String pX = find(x);
            String pY = find(y);
            if(pX.equals(pY)){
                return;
            }
            parent.put(pX, pY);
        }
    }
    
}
