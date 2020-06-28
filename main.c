
#include <malloc.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "IntVector.h"

int main() {
        IntVector* v = int_vector_new(5);
        for (int i = 1; i < 4; i++) {
                int_vector_push_back(v, i);
        }
        printf("Original size/capacity: %lu/%lu", int_vector_get_size(v),
               int_vector_get_capacity(v));
        printf("\nOriginal array: ");
        for (int i = 0; i < (v->size); i++) {
                printf("%d ", int_vector_get_item(v, i));
        }
        printf("\n");
        IntVector* copy = int_vector_copy(v);
        printf("Copy size/capacity: %lu/%lu", int_vector_get_size(copy),
               int_vector_get_capacity(copy));
        printf("\nCopied array: ");
        for (int i = 0; i < (copy->size); i++) {
                printf("%d ", int_vector_get_item(copy, i));
        }
        int_vector_push_back(copy, 0);
        int_vector_push_back(v, 1);
        printf("\nElements pushed to both arrays");

        printf("\nOriginal size/capacity: %lu/%lu", int_vector_get_size(v),
               int_vector_get_capacity(v));
        printf("\nOriginal array: ");
        for (int i = 0; i < (v->size); i++) {
                printf("%d ", int_vector_get_item(v, i));
        }
        printf("\n");

        printf("Copy size/capacity: %lu/%lu", int_vector_get_size(copy),
               int_vector_get_capacity(copy));
        printf("\nCopied array: ");
        for (int i = 0; i < (copy->size); i++) {
                printf("%d ", int_vector_get_item(copy, i));
        }

        int_vector_pop_back(v);
        int_vector_pop_back(copy);
        printf("\nElements popped from both arrays");

        printf("\nOriginal size/capacity: %lu/%lu", int_vector_get_size(v),
               int_vector_get_capacity(v));
        printf("\nOriginal array: ");
        for (int i = 0; i < (v->size); i++) {
                printf("%d ", int_vector_get_item(v, i));
        }
        printf("\n");
		
		 printf("Copy size/capacity: %lu/%lu", int_vector_get_size(copy),
               int_vector_get_capacity(copy));
        printf("\nCopied array: ");
        for (int i = 0; i < (copy->size); i++) {
                printf("%d ", int_vector_get_item(copy, i));
        }

        printf("\n");
        int_vector_shrink_to_fit(v);
        int_vector_shrink_to_fit(copy);
        printf("\nArrays shrinked to fit their sizes (expected 3/3 both)");

        printf("\nOriginal size/capacity: %lu/%lu", int_vector_get_size(v),
               int_vector_get_capacity(v));
        printf("\nOriginal array: ");
        for (int i = 0; i < (v->size); i++) {
                printf("%d ", int_vector_get_item(v, i));
        }
        printf("\n");

        printf("Copy size/capacity: %lu/%lu", int_vector_get_size(copy),
               int_vector_get_capacity(copy));
        printf("\nCopied array: ");
        for (int i = 0; i < (copy->size); i++) {
                printf("%d ", int_vector_get_item(copy, i));
        }

        int_vector_resize(v, 5);
        int_vector_resize(copy, 2);
        printf("\nArrays resized to 5 and 2 (expected 5/5 and 2/3");

        printf("\nOriginal size/capacity: %lu/%lu", int_vector_get_size(v),
               int_vector_get_capacity(v));
        printf("\nOriginal array: ");
        for (int i = 0; i < (v->size); i++) {
                printf("%d ", int_vector_get_item(v, i));
        }
        printf("\n");

        printf("Copy size/capacity: %lu/%lu", int_vector_get_size(copy),
               int_vector_get_capacity(copy));
        printf("\nCopied array: ");
        for (int i = 0; i < (copy->size); i++) {
                printf("%d ", int_vector_get_item(copy, i));
        }

        int_vector_reserve(v, 7);
        int_vector_reserve(copy, 4);
        printf("\nAdditional memory reserved (expected 5/7 and 2/4");

        printf("\nOriginal size/capacity: %lu/%lu", int_vector_get_size(v),
               int_vector_get_capacity(v));
        printf("\nOriginal array: ");
        for (int i = 0; i < (v->size); i++) {
                printf("%d ", int_vector_get_item(v, i));
        }
        printf("\n");
		
		 printf("Copy size/capacity: %lu/%lu", int_vector_get_size(copy),
               int_vector_get_capacity(copy));
        printf("\nCopied array: ");
        for (int i = 0; i < (copy->size); i++) {
                printf("%d ", int_vector_get_item(copy, i));
        }
        printf("\n\nPushing 2 elems to orig and 3 elems to copy");
        int_vector_push_back(v, 1);
        int_vector_push_back(v, 3);
        int_vector_push_back(copy, 1);
        int_vector_push_back(copy, 3);
        int_vector_push_back(copy, 1);

        printf("\nOriginal size/capacity: %lu/%lu", int_vector_get_size(v),
               int_vector_get_capacity(v));
        printf("\nOriginal array: ");
        for (int i = 0; i < (v->size); i++) {
                printf("%d ", int_vector_get_item(v, i));
        }
        printf("\n");

        printf("Copy size/capacity: %lu/%lu", int_vector_get_size(copy),
               int_vector_get_capacity(copy));
        printf("\nCopied array: ");
        for (int i = 0; i < (copy->size); i++) {
                printf("%d ", int_vector_get_item(copy, i));
        }
        printf("\n");

        int_vector_free(v);
        int_vector_free(copy);
        return 0;
}
