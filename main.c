#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

struct array {
  int *data;
  size_t capacity;
  size_t size;
};

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

size_t array_search_sorted(const struct array *self, int value) {
    if(value > self->data[self->size-1] || value < self->data[0]){
        return self->size;
    }


    size_t min = 0, max = self->size;
    size_t mid = 0;
    while(max != min){
        mid = (min + max)/2;
        if(self->data[mid] == value){
            return mid;
        }
        if(self->data[mid] > value){
            max = mid;
        }else{
            min = mid;
        }
    }
    return self->size;
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

int main(){
    struct array *tab = malloc(sizeof(struct array));
    array_create(tab);

  for (int i = 0; i < 1000; ++i) {
    array_add(tab, 2*i);
  }

  size_t index;

  for (int i = 0; i < 1000; ++i) {
    index = array_search_sorted(tab, 2*i);
    printf("index : %lu \t i : %d\n", index, 2*i);
    //EXPECT_EQ(index, static_cast<size_t>(i));
  }
    index = array_search_sorted(tab, 2001);
    printf("index : %lu \t i : %d\n",index, 2001);
    index = array_search_sorted(tab, -1);
    printf("index : %lu \t i : %d\n",index, -1);

    /*printf("%d\n",array_size(tab));
    printf("tab->data : %d\n", tab->data);
    for(size_t i = 0; i < tab->capacity; ++i){
        printf("tab->data[%lu] = %d\n", i, tab->data[i]);
    }

    size_t taille = 10;
    int *ar = calloc(taille, sizeof(int));
    ar[3]=0;
    bool b = array_equals(tab, ar, taille);
    printf("%d\n", b);

    for(size_t i = 0; i < 10; ++i){
        array_add(tab, rand());
    }
    printf("\n");

    //array_remove(tab, 5);
    for(size_t i = 0; i < tab->size; ++i){
        printf("tab->data[%lu] = %d\n", i, tab->data[i]);
    }

    printf("\n\n\n************\n");

    array_dump(tab);

    for(size_t i = 0; i < 10; ++i){
        array_add(tab, rand());
    }

    array_dump(tab);
    printf("is sorted : %s\n",array_is_sorted(tab) ? "true" : "false");

    printf("\n");
    //array_selection_sort(tab);
    array_selection_sort(tab);
    array_dump(tab);
    printf("is sorted : %s\n",array_is_sorted(tab) ? "true" : "false");


*/
    array_destroy(tab);
    return 0;
}
