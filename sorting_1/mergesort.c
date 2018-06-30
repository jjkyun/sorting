/*
left, right: address of first location
*/
void merge(int* left, int* right, int left_size, int right_size){
    int sort_arr[left_size + right_size];
    int i = 0;
    int j = 0;
    int k = 0;
    
    // compare until i, j get to the max size
    while(i < left_size && j < right_size){
        if(left[i] < right[j]){
            sort_arr[k] = left[i];
            k++;
            i++;
        }
        else{
            sort_arr[k] = right[j];
            k++;
            j++;
        }
        
    }

    // if comparing is finished, put resident data in order
    while(i < left_size){
        sort_arr[k] = left[i];
        k++;
        i++;
    }
    while(j < right_size){
        sort_arr[k] = right[j];
        k++;
        j++;
    }

    // now copy sorted array to origin array using left pointer
    for(i=0; i < left_size + right_size; i++){
        left[i] = sort_arr[i];
    }
}

/*
parameter: gets first loc address of array and array size
Divide and Conquer it by recursive way
*/
void mergeSort(int* arr, int size) 
{   
    // Divide
    int mid = size/2;

    if(size <= 1){
        return;
    }
    
    // Conquer
    mergeSort(arr, mid); // left recursion
    mergeSort(arr+mid, size-mid); // right recursion
    
    // Combine
    merge(arr, arr+mid, mid, size-mid);
}

