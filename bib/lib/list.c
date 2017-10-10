#include "list.h"

struct list_node {
  int value;
  struct list_node *next;
  // struct list_node *prev;
};

void list_create(struct list *self) {

}

void list_destroy(struct list *self) {

}

bool list_equals(const struct list *self, const int *data, size_t size) {

  return false;
}

void list_add_back(struct list *self, int value) {

}

void list_add_front(struct list *self, int value) {
  
}

void list_insert(struct list *self, int value, size_t index) {

}

void list_remove(struct list *self, size_t index) {

}

int *list_get(const struct list *self, size_t index) {

  return NULL;
}

bool list_is_empty(const struct list *self) {

  return false;
}

size_t list_size(const struct list *self) {

  return 0;
}

size_t list_search(const struct list *self, int value) {

  return 0;
}

void list_import(struct list *self, const int *other, size_t size) {

}

void list_dump(const struct list *self) {

}

bool list_is_sorted(const struct list *self) {

  return false;
}


void list_merge_sort(struct list *self) {

}
