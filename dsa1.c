#include <stdio.h>
#include <stdlib.h>

#include "sorting_algorithm.h"


void createArray(struct myArray* array, int total_space, int used_space){
    array->total_space = total_space;
    array->used_space = used_space;
    array->ptr = (int*) malloc(total_space * sizeof(int));
}

void traverse_array(struct myArray* array){
    for(int i = 0; i < array->used_space; i++){
        printf("index: %d, value: %d\n", i, array->ptr[i]);
    }
}

void add_sequence_to_array(struct myArray* array){
    for(int i = 0; i < array->total_space; i++){
        array->ptr[i] = i + 100;
    }   
}

void insert_element(struct myArray * array, int element){
    array->ptr[array->used_space] = element;
    array->used_space++;
}

int get_index(struct myArray * array, int element){
    for(int i = 0; i < array->used_space; i++){
        if (array->ptr[i] == element){
            return i;
        }
    }
    return -1;    
}

void delete_index(struct myArray * array, int index){
    while(index < array->used_space){
        array->ptr[index] = array->ptr[index + 1];
        index ++;
    }
    array->used_space--;
}

void main(){
    printf("hello world\n");
    struct myArray myarray;
    myarray.total_space = 10;
    printf("Structure : %d\n", myarray.total_space);
    createArray(&myarray, 10, 2);
    printf("Structure : %d\n", myarray.used_space);
    add_sequence_to_array(&myarray);
    traverse_array(&myarray);
    insert_element(&myarray, 11);
    traverse_array(&myarray);
    int indexof = get_index(&myarray, 100);
    delete_index(&myarray, indexof);
    bubble_sort(&myarray);
    // swap(&myarray.ptr[0], &myarray.ptr[1]);           

    traverse_array(&myarray);
}