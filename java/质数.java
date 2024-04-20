import java.util.ArrayList;
import java.util.List;

import org.junit.Test;
class QWE {
    {System.out.println("qwe");}
    static {System.out.println("asd");}
    
}

class ASD extends QWE {
    {System.out.println("1qwe");}
    static {System.out.println("1asd");}
    
}
public class 质数 {
    
    @Test
    public void test() {
        // System.out.println(PrimeSum(56));
        System.out.println(solution("red2 blue5 black4 green1 gold3"));
        


        
    }

    public String solution(String s){
        String[] arr = s.split(" ");
        String[] res = new String[arr.length];
        StringBuilder sb = new StringBuilder();
        for(String asd: arr){
            // System.out.println(asd);
            // System.out.println();
            int index = Integer.parseInt(String.valueOf(asd.charAt(asd.length()-1)));
            // System.out.println(index);

            res[index-1] = asd.substring(0, asd.length()-1); 

        }
        for(String asd: res){
            sb.append(asd);
            sb.append(' ');
        }
        return sb.toString().substring(0, sb.toString().length()-1);
    }

    // 给定一个数，判断能否在素数表中找到连续的几个素数之和表示它。M<e9
    public boolean PrimeSum(int M) {
        List<Integer> list = new ArrayList();
        for (int i = 0; i < 5e3; i++) {
            if (isPrime2(i))
                list.add(i);
        }
        int l = list.size();
        for (int i = 0; i < l; i++) {
            if (list.get(i) > M)
                break;
            if (list.get(i) == M)
                return true;
            int sum = list.get(i);
            for (int j = i + 1; j < l; j++) {
                if (sum + list.get(j) > M)
                    break;
                else if (sum + list.get(j) == M)
                    return true;
                else
                    sum += list.get(j);
            }
        }
        return false;
    }

    public boolean isPrime(int a) {
        if (a <= 1)
            return false;
        int sqrt = (int) Math.sqrt(a);

        for (int i = 2; i <= sqrt; i++) {
            if (a % i == 0)
                return false;
        }
        return true;
    }

    public boolean isPrime2(int a) {
        if (a <= 3)
            return a > 1;
        if (a % 6 != 1 && a % 6 != 5)
            return false;
        int sqrt = (int) Math.sqrt(a);
        for (int i = 5; i <= sqrt; i += 6) {
            if (a % i == 0 || a % (i + 2) == 0)
                return false;
        }
        return true;

    }

}
