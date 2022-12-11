#include<stdio.h>


struct myArray{
    int total_space;
    int used_space;
    int* ptr;
};


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
void merge_sort(struct myArray* array);
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
	for(int i = 0; i < array->used_space; i++){
		for(int j = i; j > 0; j--){
			if(array->ptr[j-1] > array->ptr[j]){
				swap(&array->ptr[j-1], &array->ptr[j]);
			}
		}
	}
}
