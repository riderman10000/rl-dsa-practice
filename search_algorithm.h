#include <stdio.h>
#include <stdlib.h>

int linear_search(struct myArray* array, int element);
int binary_search(struct myArray* array, int element);

int linear_search(struct myArray* array, int element){
	for(int i = 0; i < array->used_space; i++){
		if(array->ptr[i] == element){
			return i;
		}
	}
	return -1;
}

int binary_search(struct myArray* array, int element){
	printf("This is the binary_search\n");
	// call sorting algorithm before calling this function
	// it partion the organized array
	int left = 0, right = array->used_space;
	int mid = left + (right - left)/2;
	while(left<=right){
		if(array->ptr[mid] == element){
			return mid;
		}
		else if(element <= array->ptr[mid-1]){
			right = mid-1;
		}
		else{
			left = mid + 1;
		}
		mid = left + (right - left)/2;
	}
	return -1;
}