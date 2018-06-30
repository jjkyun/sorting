#include <stdio.h>
#include <stdlib.h>

// swap function
void swap(int* arr, int i, int j){
        int temp;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
}

// partitioning, return the location of pointer
int partition(int* arr, int start, int end)
{
   int pivot = arr[start];
   int i = start;

   // Comparing by looping the array 
   for(int j = i+1; j <= end; j++){
       // if smaller than pivot, go to left side
       if(pivot >= arr[j]){
          i++;
          swap(arr, i, j);
       }
   }
   swap(arr, start, i);
   return i;
}

// randomize the pivot point
int partition_random(int* arr, int start, int end){
    int random_p;
    random_p = rand() % (end-start+1) + start;
    swap(arr, start, random_p);
    partition(arr, start, end);
}

void quickSort1(int* arr, int start, int end) 
{
    int p; // p = partitiong index
    
    // Array size should be at least 2
    if (start < end)
    {
        p = partition_random(arr, start, end);

        quickSort1(arr, start, p - 1);
        quickSort1(arr, p + 1, end);
    }
}


void quickSort(int* arr, int size){
    // index of start and end
    int start = 0;
    int end = size - 1;
    
    // giving start and end index
    quickSort1(arr, start, end);
}
