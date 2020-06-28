
#include "IntVector.h"
#include <malloc.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

IntVector* int_vector_new(size_t initial_capacity) {
        IntVector* v = malloc(sizeof(IntVector));
        v->vector = calloc(initial_capacity, sizeof(int));
        v->capacity = initial_capacity;
        v->size = 0;
        if (v->vector == NULL) {
                free(v);
                return NULL;
        }
        if (v == NULL) {
                free(v->vector);
                return NULL;
        }
        return v;
}

void int_vector_set_item(IntVector* v, size_t index, int item) {
        if (index >= 0 && index < v->size) {
                v->vector[index] = item;
        } else
                printf("\nInvalid index. Item was not set.");
}

IntVector* int_vector_copy(const IntVector* v) {
        IntVector* copy = int_vector_new(v->capacity);
        if (copy == NULL) return NULL;
        copy->size = v->size;
        for (int i = 0; i < copy->size; i++) {
                copy->vector[i] = v->vector[i];
        }
        return copy;
}

void int_vector_free(IntVector* v) {
        if (v->vector != NULL || v != NULL) {
                free(v->vector);
                free(v);
        }
}

int int_vector_get_item(const IntVector* v, size_t index) {
        if (index < (v->size) && index >= 0) {
                return v->vector[index];
        }
        return -1;
}

size_t int_vector_get_size(const IntVector* v) { return v->size; }

size_t int_vector_get_capacity(const IntVector* v) { return v->capacity; }

int int_vector_push_back(IntVector* v, int item) {
        if (v->size < v->capacity) {
                v->vector[v->size] = item;
                v->size++;
        } else {
                if (realloc(v, sizeof(int) * ((v->capacity) + 15)) == NULL) {
                        return -1;
                }
                v->capacity += 15;
                v->vector[v->size] = item;
                v->size++;
        }
        int k = int_vector_get_item(v, (v->size) - 1);
        if (k == item) {
                return 0;
        } else {
                return -1;
        }
}

void int_vector_pop_back(IntVector* v) {
        if (v->size > 0) {
                v->vector[(v->size) - 1] = 0;
                v->size--;
        } else {
                printf("\nArray has no elements");
        }
}

int int_vector_shrink_to_fit(IntVector* v) {
        IntVector* copy = int_vector_copy(v);
        if (copy == NULL) return -1;

        v->vector = realloc(v->vector, sizeof(int) * (v->size));
        v->capacity = v->size;
        for (int i = 0; i < (copy->size); i++) {
                copy->vector[i] = v->vector[i];
        }
        if (v->vector == NULL) {
                return -1;
        }
        int_vector_free(copy);
        return 0;
}

int int_vector_reserve(IntVector* v, size_t new_capacity) {
        if (new_capacity > (v->capacity)) {
                IntVector* copy = int_vector_copy(v);
                v->vector = realloc(v->vector, sizeof(int) * new_capacity);
                v->capacity = new_capacity;
                size_t before_index = copy->size;
                for (int i = 0; i < before_index; i++) {
                        v->vector[i] = copy->vector[i];
                }
                if (v->vector == NULL) {
                        return -1;
                }
                int_vector_free(copy);
                return 0;
        } else
                return 0;
}

int int_vector_resize(IntVector* v, size_t new_size) {
        if (new_size > (v->size) && (v->capacity) >= new_size) {
                size_t before_index = (v->size) - 1;
                v->size = new_size;
                for (int i = before_index; i < new_size; i++) {
                        v->vector[i] = 0;
                }
                printf("\nVector resized");
                return 0;
        } else if (new_size > (v->size) && (v->capacity) < new_size) {
                int k = int_vector_reserve(v, new_size);
                v->size = new_size;
                if (k == 0) {
                        printf("\nVector resized");
                        return 0;
                }
                printf("\nVector resize failed");
                int_vector_free(v);
                return -1;

        } else if (new_size < (v->size)) {
                size_t backup = v->size;
                v->size = new_size;
                int k = int_vector_shrink_to_fit(v);
                if (k == -1) {
                        printf("\nVector resize failed");
                        v->size = backup;
                        return -1;
                }
                printf("\nVector resized");
                return 0;
        }
        return 0;
}
