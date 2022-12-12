#include <stdio.h>
#include <stdlib.h>

struct myArray{
    int total_space;
    int used_space;
    int* ptr;
};

// function for the array... 
void createArray(struct myArray* array, int total_space, int used_space);
void traverse_array(struct myArray* array);
void add_sequence_to_array(struct myArray* array);
void insert_element(struct myArray * array, int element);
int get_index(struct myArray * array, int element);
void delete_index(struct myArray * array, int index);

// implementation of the above functions 

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
    for(int i = 0; i < array->used_space; i++){
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
