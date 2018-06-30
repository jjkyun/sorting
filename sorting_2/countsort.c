#include <stdio.h>

void countSort(int* arr, int size)
{
    int sorted_arr[size];
    // find max value first
    int max = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    
    int count_arr[max];
    // Initalizing count array starting from 0
    for(int i = 0; i < max; i++){
        count_arr[i] = 0;
    }
    
    // Counting frequency from array to count array
    for(int j = 0; j < size; j++){
       // index 0 = value 1 
       count_arr[arr[j]-1]++; 
    }
    
    // Updating the count array
    for(int i = 1; i < max; i++){
        count_arr[i] = count_arr[i] + count_arr[i-1];
    }
    
    // Sorting the array from end point according to count array
    for(int j = size-1; j >= 0; j--){
        sorted_arr[count_arr[arr[j]-1]-1] = arr[j];
        count_arr[arr[j]-1]--;
    }

    // Copy sorted array to origin array
    for(int j = 0; j < size; j++){
        arr[j] = sorted_arr[j];
    }
}
