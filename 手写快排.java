package com;
import org.junit.Test;
public class 手写快排 {


    @Test
    public void test(){

        int[] input = new int[]{3,4,5,2,1,6,5,4,3,1,2,9};
        int[] input3 = new int[]{3,4,5,2,1,6,5,4,3,1,2,9, 9};
        QS2(input, 0, input.length-1);
        QS2(input3, 0, input3.length-1);
        for(int i : input){
            System.out.print(i+" ");
        }


    }
    //{3,4,5,2,1,6,5,4,3,1,2,9};
    public void QuickSort(int[] input,int left,int right){
        if(left>=right) return;
        
        int initLeft = left;
        int initRight = right;
        int rand = input[initLeft];
        while(left<right){
            while(input[right]>=rand&&left<right) right--;
            while(input[left]<=rand&&left<right) left++;
            Switch(input, left, right);
        }
        Switch(input, initLeft, left);
        QuickSort(input, initLeft, left-1);
        QuickSort(input, left+1, initRight);
    }



    public void Switch(int[] input,int left,int right){
        int temp = input[left];
        input[left] = input[right];
        input[right] = temp;

    }



    public void QS(int[] input,int left,int right){
        if(left>=right) return;
        int initLeft = left;
        int initRight = right;
        int rand = input[initLeft];
        while(left<right){
            while(input[right]>=rand&&left<right) right--;
            while(input[left]<=rand&&left<right) left++;
            Switch(input, left, right);
        }
        Switch(input, initLeft, left);
        QS(input, initLeft, left-1);
        QS(input, left+1, initRight);
        
    }
    



    public void QS2(int[] input,int left,int right){
        if(left>=right) return;
        int initLeft = left, initRight = right;
        int ran = input[initLeft];
        while(left<right){
            while(input[right]>=ran&&left<right) right--;
            while(input[left]<=ran&&left<right) left++;
            Switch(input, left, right);
        }
        Switch(input, initLeft, left);
        QS2(input, initLeft, left-1);
        QS2(input, left+1, initRight);


    }



}