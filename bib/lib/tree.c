#include "tree.h"

struct tree_node {
  int value;
  struct tree_node *left;
  struct tree_node *right;
};

void tree_create(struct tree *self) {

}

void tree_destroy(struct tree *self) {

}

bool tree_contains(const struct tree *self, int value) {

  return false;
}

void tree_insert(struct tree *self, int value) {

}

void tree_remove(struct tree *self, int value) {

}

bool tree_is_empty(const struct tree *self) {
  return false;
}

size_t tree_size(const struct tree *self) {

  return 0;
}

size_t tree_height(const struct tree *self) {

  return 0;
}

void tree_walk_pre_order(const struct tree *self, tree_func_t func, void *user_data)  {

}

void tree_walk_in_order(const struct tree *self, tree_func_t func, void *user_data) {

}

void tree_walk_post_order(const struct tree *self, tree_func_t func, void *user_data) {

}

void tree_dump(const struct tree *self) {
  
}
