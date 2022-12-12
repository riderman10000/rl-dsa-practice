#include <stdio.h>
#include <stdlib.h>

#include "my_array.h"
#include "sorting_algorithm.h"

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
    insert_element(&myarray, 10);
    insert_element(&myarray, 21);
    insert_element(&myarray, 20);
    insert_element(&myarray, 17);
    
    traverse_array(&myarray);
    
    int indexof = get_index(&myarray, 100);
    delete_index(&myarray, indexof);
    
    merge_sort(&myarray, 0, myarray.used_space);
    traverse_array(&myarray);
}