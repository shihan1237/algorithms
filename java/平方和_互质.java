import java.util.ArrayList;
import java.util.List;

import org.junit.Test;

public class 平方和_互质 {
    
    @Test
    public void test(){
        List<List<Integer>> res = new ArrayList();
        fun(1,20,res);
        for(List<Integer> list: res){
            for(int i: list){
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }
    public static void fun(int N, int M, List<List<Integer>> res){
        for(int i = N; i<=M-2;i++){
            for(int j = i+1; j<=M-1;j++){
                double k = Math.sqrt(Math.pow(i,2)+Math.pow(j,2));
                if(k-(int)k!=0) continue;
                if(k>M) continue;
                if(huZhi(i,j)&&huZhi(i,(int)k)&&huZhi((int)k,j)){
                    int ii = i, jj = j;
                    res.add(new ArrayList(){{
                        add(ii);
                        add(jj);
                        add((int)k);
                    }});
                }
            }
        }
    }
    
    public static boolean huZhi(int x, int y){
        int tmp;
        if(x<y){
            tmp = x;
            x = y;
            y = tmp;
        }
        while((tmp = x%y)!=0){
            x = y;
            y = tmp;
        }
        return y == 1;
        // return true;
    }
}
