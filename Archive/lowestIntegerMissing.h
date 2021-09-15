//Given and array of integers, find the first missing positive integer in linear time and constant space.
//In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative
//numbers as well.

//For example: [3,4,-1,1] should give 2. The input [1,2,0] should give 3.

//You can modify input array in-place.

int segregate(int* array, int size){
    int j = 0;
    int i = 0;
    for(; i < size; ++i){
        if(array[i] <= 0){
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            ++j;
        }
    }
    return j;
}

int findMissing(int* array, int size){
    for(int i = 0; i < size; ++i){
        if(array[i] < 0){
            int data = -1 * array[i];
            if(data > size) continue;
            array[data - 1] *= -1;
        }
        if(array[i] > size) continue;
        array[array[i]-1] *= -1;
    }
    for(int i = 0; i < size; ++i){
        if(array[i] > 0) return i + 1;
    }
    return size + 1;
}

int lowestIntegerMissing(int* array, int size){
    int j = segregate(array, size);
    return findMissing(array + j, size - j);
}