import org.junit.Test;

//单调二分找最接近的两种思路：
//1，每一个mid都进行abs比较，取最小的abs
//2，二分查找结束后，对left进行左值ABS对比（需注意范围、存在问题），不需要对右值对比，因为（left = mid+1），所以左值是可能跳过的
public class BinarySearch {
    @Test
    public void test(){
        int[] ints = new int[]{1,2,3,3,4,11,12,13};
        // 1,2,3,4,10,10,10,10:  10
        find(10, ints);
    }
    
    //法2
    public static void find(int theM, int[] bookSheet){
        int left = 0, right = bookSheet.length-1;
        int mid = 0;
        while(left<right){
            mid = (left+right)/2;
            if(bookSheet[mid]<theM) left = mid+1;
            else right = mid;
        }
        int res = left;
        if(left-1>=0){
            if(Math.abs(bookSheet[left-1]-theM)<Math.abs(bookSheet[left]-theM)) res = left-1;
        }
        System.out.println(res);
        
        
    }
    //法1
    public static void find2(int theM, int[] bookSheet){
        int left = 0, right = bookSheet.length-1;
        int mid = 0;
        
        int resABS = Integer.MAX_VALUE;
        int res = 0;

        while(left<right){
            mid = (left+right)/2;

            int cur = Math.abs(bookSheet[mid]-theM);
            if(cur<resABS){
                res = mid;
                resABS = cur;
            }

            if(bookSheet[mid]<theM) left=mid+1;
            else right = mid;
        }
        System.out.println(res);
        
        
    }


}
