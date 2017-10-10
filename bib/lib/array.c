#include "array.h"


void array_create(struct array *self) {
    self->capacity = 10;
    self->size = 0;
    self->data = calloc(self->capacity,sizeof(int));
    if(self->data == NULL){
        printf("ERREUR probleme de memoire.");
        exit(1);
    }
}

void array_destroy(struct array *self) {
    free(self->data);
}

bool array_equals(const struct array *self, const int *content, size_t size) {
    if(self->size == size){
        for(size_t i = 0; i < size; ++i){
            if(self->data[i] != *(content + i)){
                return false;
            }
        }
        return true;
    }
    return false;
}

void array_add(struct array *self, int value) {
    if(self->size == self->capacity){
        self->capacity *= 2;
        int *data = calloc(self->capacity, sizeof(int));
        memcpy(data, self->data, self->size * sizeof(int));
        free(self->data);
        self->data = data;
    }
    self->data[self->size] = value;
    self->size += 1;
}

void array_insert(struct array *self, int value, size_t index) {
    if(self->size == self->capacity){
        self->capacity *= 2;
        int *data = calloc(self->capacity, sizeof(int));
        memcpy(data, self->data, self->size * sizeof(int));
        free(self->data);
        self->data = data;
    }
    for(size_t i = self->size - 1; i != index; --i){
        self->data[i + 1] = self->data[i];
    }
    self->data[index] = value;
}

void array_remove(struct array *self, size_t index) {
    for(size_t i = index; i < self->size; ++i){
        self->data[i] = self->data[i + 1];
    }
    --self->size;
}

int *array_get(const struct array *self, size_t index) {
    if(index >= self->size){
        return NULL;
    }
    return &self->data[index];
}
bool array_is_empty(const struct array *self) {
    if(self->size == 0){
        return true;
    }
    return false;
}

size_t array_size(const struct array *self) {
  return self->size;
}

size_t array_search(const struct array *self, int value) {
    for(size_t i = 0; i < self->size; ++i){
        if(self->data[i] == value){
            return i;
        }
    }
    return self->size;
}

size_t array_search_sorted_dichotomique(const struct array *self, int value, size_t min,  size_t max){
    if(min == max){
            printf("0");
        return min;
    }
    size_t mid = (max + min)/2;
    if(value > self->data[mid]){
        return array_search_sorted_dichotomique(self, value, mid + 1, max);
    }
    if(value < self->data[mid]){
        return array_search_sorted_dichotomique(self, value, min, mid - 1);
    }
    printf("1");
    return mid;
}

size_t array_search_sorted(const struct array *self, int value) {
    if(value > self->data[self->size-1]){
        return self->size;
    }
    if(value < self->data[0]){
        return self->size;
    }
    return array_search_sorted_dichotomique(self,value, 0, self->size);
}

void array_import(struct array *self, const int *other, size_t size) {
    self->size = size;
    self->capacity = size*2;
    self->data = realloc(self->data, self->capacity*sizeof(int));
    memcpy(self->data, other, size);
}

void array_dump(const struct array *self) {
    for(size_t i = 0; i < self->size; ++i){
        printf("%d\n", self->data[i]);
    }
}

bool array_is_sorted(const struct array *self) {
    for(size_t i = 1; i < self->size; ++i){
        if(self->data[i-1] > self->data[i]){
            return false;
        }
    }
    return true;
}

void array_swap (int *data, size_t i, size_t j){
    int tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
}

void array_selection_sort(struct array *self) {
    size_t min = 0;
    for(size_t i = 0; i < self->size; ++i){
        min = i;
        for(size_t j = i; j < self->size; ++j){
            if(self->data[min] > self->data[j]){
                min = j;
            }
        }
        array_swap(self->data, min, i);
    }
}

void array_bubble_sort(struct array *self) {
    for(size_t i = 0; i < self->size; ++i){
        for(size_t j = 0; j < self->size - i - 1; ++j){
            if(self->data[j] > self->data[j + 1]){
                array_swap(self->data, j, j+1);
            }
        }
    }
}

void array_insertion_sort(struct array *self) {
    for(size_t i = 1; i < self->size; ++i){
        int tmp = self->data[i];
        int j = i;
        while(tmp < self->data[j-1] && j > 0){
            self->data[j] = self->data[j -1];
            --j;
        }
        self->data[j] = tmp;
    }
}


void array_quick_sort(struct array *self) {

}

void array_heap_sort(struct array *self) {

}


bool array_is_heap(const struct array *self) {
  return false;
}

void array_heap_add(struct array *self, int value) {

}

int array_heap_top(const struct array *self) {
  return 0;
}

void array_heap_remove_top(struct array *self) {

}
