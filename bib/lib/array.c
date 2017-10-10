#include "array.h"

void array_create(struct array *self) {
	self->capacity=10;
	self->size=0;
	self->data=malloc(self->capacity*sizeof(int));
}

void array_destroy(struct array *self) {
	free(self->data);
}

bool array_equals(const struct array *self, const int *content, size_t size) {
	if (self->size==size)
	{
		for (size_t i=0; i<self->size;i++)
		{
			if (self->data[i]!=content[i])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

void array_add(struct array *self, int value) {
	if (self->size == self->capacity) {
		self->capacity *=2;
		int *data = calloc(self->capacity, sizeof(int));
		memcpy(data, self->data, self->size * sizeof(int));
		free(self->data);
		self->data = data;
	}
	self->data[self->size] = value;
	self->size += 1;
}

void array_insert(struct array *self, int value, size_t index) {
	if (self->size == self->capacity) {
		self->capacity *=2;
		int *data = calloc(self->capacity, sizeof(int));
		memcpy(data, self->data, self->size * sizeof(int));
		free(self->data);
		self->data = data;
	}
	int tmp;
	for (size_t i=0; i<self->size-index; i++)
	{
		tmp=self->data[i+index];
		self->data[i+index]=value;
		value=tmp;
	}
	self->data[self->size] = value;
	self->size += 1;
}

void array_remove(struct array *self, size_t index) {
	for (size_t i=0; 1+i<self->size-index;i++)
	{
		self->data[(i+index)]=self->data[(i+index+1)];
	}
	self->size-=1;
}

int *array_get(const struct array *self, size_t index) {
	if (index>=self->size || index<0)
	{
		return NULL;
	}
	int* tmp = &self->data[index];
	return tmp;
}

bool array_is_empty(const struct array *self) {
	if (self->size==0)
	{
		return true;
	}
	return false;
}

size_t array_size(const struct array *self) {
	return self->size;
}

size_t array_search(const struct array *self, int value) {
	size_t index=self->size;
	for (size_t i=0; i<self->size; i++)
	{
		if (self->data[i]==value)
		{
			index=i;
			break;
		}
	}
	return index;
}

size_t array_search_sorted(const struct array *self, int value) {
	size_t index=self->size;
	for (size_t i=0; i<self->size; i++)
	{
		if (self->data[i]==value)
		{
			index=i;
			break;
		}

		if (self->data[i]>value)
		{
			break;
		}
	}
	return index;
}

void array_import(struct array *self, const int *other, size_t size) {
	self->size=size;
	self->capacity=size;
	self->data=realloc(self->data, self->size*sizeof(int));
	memcpy(self->data, other,self->size*sizeof(int));
}

void array_dump(const struct array *self) {
	for (size_t i=0; i<self->size; i++)
	{
		fprintf(stdout,"%d\n", self->data[i]);
	}
}

bool array_is_sorted(const struct array *self) {
	bool res=true;
	for (size_t i=1; i<self->size; i++)
	{
		if (self->data[i-1]>self->data[i])
		{
			res=false;
			break;
		}
	}
	return res;
}

void array_swap(int *data, size_t i, size_t j) {
	int tmp = data[i];
	data[i] = data[j];
	data[j] = tmp;
}

void array_selection_sort(struct array *self) {
	for (size_t i = 0; i < self->size - 1; ++i)
	{
		size_t j = i;
		for (size_t k = j + 1; k < self->size; ++k)
		{
			if (self->data[k] < self->data[j])
			{
				j = k;
			}
		}
	array_swap(self->data, i, j);
	}
}

void array_bubble_sort(struct array *self) {
	for (size_t i = 0; i < self->size - 1; ++i)
	{
		for (size_t j = self->size - 1; j > i; --j)
		{
			if (self->data[j] < self->data[j - 1])
			{
				array_swap(self->data, j, j - 1);
			}
		}
	}
}

void array_insertion_sort(struct array *self) {
	for (size_t i = 1; i < self->size; ++i)
	{
		int x = self->data[i];
		size_t j = i;
		while (j > 0 && self->data[j - 1] > x)
		{
			self->data[j] = self->data[j - 1];
			j--;
		}
		self->data[j] = x;
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
