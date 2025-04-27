#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 2

typedef struct {
    size_t size;
    size_t capacity;
    int* array;
} dynamic_array;

dynamic_array* array() {
    dynamic_array* arr = (dynamic_array*) malloc(sizeof(dynamic_array));
    if (!arr){
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    arr->size = 0;
    arr->capacity = INITIAL_CAPACITY;
    arr->array = (int*)malloc(INITIAL_CAPACITY*sizeof(int));
    if (!arr->array){
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return arr;
}

void insertArray(dynamic_array* arr, int num) {
    if (arr->size==arr->capacity){
        int* temp = arr->array;
        arr->capacity <<= 1;
        arr->array = realloc(arr->array, arr->capacity * sizeof(int));
        if (!arr->array){
            printf("Memory allocation failed\n");
            arr->array = temp;
            return;
        }
    }
    arr->array[arr->size++] = num;
}

void deleteArray(dynamic_array* arr, int index) {
    if (index >= arr->size){
        printf("Index out of range\n");
        return;
    }
    for (int i=index; i<arr->size-1; ++i){
        arr->array[i] = arr->array[i+1];
    }
    arr->size--;
}

void displayArray(dynamic_array* arr) {
    for (int i=0; i<arr->size; ++i){
        printf("%d ", arr->array[i]);
    }
    printf("\n");
}


void freeArray(dynamic_array* arr){
    free(arr->array);
    free(arr);
}

int main(){
    dynamic_array* arr = array();

    insertArray(arr, 5);
    insertArray(arr, 3);
    insertArray(arr, 2);
    insertArray(arr, 5);
    insertArray(arr, 3);
    insertArray(arr, 2);
    insertArray(arr, 5);
    insertArray(arr, 3);
    insertArray(arr, 2);
    insertArray(arr, 5);
    insertArray(arr, 3);
    insertArray(arr, 2);

    displayArray(arr);

    deleteArray(arr, 1);

    displayArray(arr);

    freeArray(arr);
    return 0;
}