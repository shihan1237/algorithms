package com;

import java.util.Arrays;

public class Bubble {

    public static void main(String[] args) {

        int[] input = new int[] { 3, 4, 5, 2, 1, 6, 5, 4, 3, 1, 2, 9 };
        sort(input);

    }

    public static void sort(int[] arr) {
        int len = arr.length;
        for (int i = len - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (arr[j] > arr[i]) {
                    Switch(arr, i, j);
                }
            }
        }
        System.out.println(Arrays.toString(arr));
    }

    public static void Switch(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

}
