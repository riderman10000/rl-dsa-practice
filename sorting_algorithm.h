#include<stdio.h>

void swap(int *a, int *b){
	// printf("value at a %d\n", *a);
	// printf("address a  %d\n",a);
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(struct myArray* array);
void bubble_sort(struct myArray* array);
void insertion_sort(struct myArray* array);
void insertion1_sort(struct myArray* array);
void merge(struct myArray* array, int left, int mid, int right);
void merge_sort(struct myArray* array, int left, int right);
void quick_sort(struct myArray* array);
void heap_sort(struct myArray* array);
void iterative_heap_sort(struct myArray* array);
void counting_sort(struct myArray* array);
void radix_sort(struct myArray* array);
void bucket_sort(struct myArray* array);

void selection_sort(struct myArray* array){
	int min_element_index = 0;
	for (int i =0; i < array->used_space; i++){
		for(int j = i; j < array->used_space; j++){
			if( array->ptr[j] < array->ptr[min_element_index]){
				min_element_index = j;
			}
		}
		if(min_element_index != i){
			swap(&array->ptr[i], &array->ptr[min_element_index]);			
		}
	}
}

void bubble_sort(struct myArray* array){
	for(int i =0; i < array->used_space-1; i++){
		for(int j = 0; j < array->used_space - i - 1 ; j++){
			// last i elements are already in place
			if(array->ptr[j+1] < array->ptr[j]){
				swap(&array->ptr[j+1], &array->ptr[j]);
			}
		}
	}
}


void insertion_sort(struct myArray* array){
// works similar to card playing 
// you take the a card, then go through left to right
// if you find greater card swap with the small card
	for(int i = 0; i < array->used_space; i++){
		for(int j = i; j > 0; j--){
			if(array->ptr[j-1] > array->ptr[j]){
				swap(&array->ptr[j-1], &array->ptr[j]);
			}
		}
	}
}

void insertion1_sort(struct myArray* array){
	int i, j, key;
	for(i = 1; i < array->used_space; i++){
		key = array->ptr[i];
		j = i - 1;
		// move elements of array [0...i-1]
		// that are greater than key,
		// to one position ahead of their current position
		while(j>=0 && array->ptr[j] > key){
			array->ptr[j+1] = array->ptr[j];
			j = j - 1;
		}
		array->ptr[j+1] = key;
	}
}

void merge(struct myArray* array, int left, int mid, int right){
	int i, j, k;
	int left_array_size = mid + 1 - left;
	int right_array_size = right - mid;

	// create temporary arrays
	struct myArray leftArray, rightArray;
	createArray(&leftArray, left_array_size, left_array_size);
	createArray(&rightArray, right_array_size, right_array_size);

	// copy the value from the array to the temperoray arrays
	for(i = 0 ; i < left_array_size; i++){
		leftArray.ptr[i] = array->ptr[left+i];
	}
	for(j = 0 ; j < right_array_size; j++){
		rightArray.ptr[j] = array->ptr[mid+1+j];
	}

	// merge the array back to te array in sorted manner
	i = 0;
	j = 0;
	k = left;
	while(i < left_array_size && j < right_array_size){
		if(leftArray.ptr[i] <= rightArray.ptr[j]){
			array->ptr[k] = leftArray.ptr[i];
			i++;
		}
		else{
			array->ptr[k] = rightArray.ptr[j];
			j++;
		}
		k++;
	}
	// copy the remaining elements of left and right if there is any
	while( i < left_array_size){
		array->ptr[k] = leftArray.ptr[i];
		i++, k++;
	}
	while( j < right_array_size){
		array->ptr[k] = rightArray.ptr[j];
		j++, k++;
	}
}

void merge_sort(struct myArray* array, int left, int right){
	printf("merge sort\n");
	if (left < right){
		int mid = left + (right - left) / 2;
		merge_sort(array, left, mid);
		merge_sort(array, mid + 1, right);
		merge(array, left, mid, right);
	}
}

