import java.util.Arrays;

import org.junit.Test;

public class QuickSort {

    @Test
    public void test() {
        int[] arr = new int[] { 4, 5, 6, 2, 7, 8, 1, 2, 3, 4, 1, 1 };
        quickSort(arr, 0, arr.length - 1);
        System.out.println(Arrays.toString(arr));
    }

    public void quickSort(int[] arr, int left, int right) {

        if (left > right)
            return;

        int mid = arr[left];

        int i = left, j = right;
        while (i < j) {

            while (arr[j] >= mid && i < j)
                j--;

            while (arr[i] <= mid && i < j)
                i++;

            int tmp = arr[i];

            arr[i] = arr[j];

            arr[j] = tmp;

        }
        arr[left] = arr[i];
        arr[i] = mid;

        quickSort(arr, left, i - 1);
        quickSort(arr, i + 1, right);

    }
}
