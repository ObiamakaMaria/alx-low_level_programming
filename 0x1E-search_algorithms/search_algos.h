#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * struct listint_s - singly linked list
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct listint_s
{
    int n;
    size_t index;
    struct listint_s *next;
} listint_t;


/* Function prototypes */
int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
void print_array(int *array, size_t start, size_t end);
int jump_search(int *array, size_t size, int value);
size_t min(size_t a, size_t b);
int interpolation_search(int *array, size_t size, int value);
int new_binary_search(int *array, size_t low, size_t high, int value);
int exponential_search(int *array, size_t size, int value);
void print_array(int *array, size_t low, size_t high);
int advanced_binary(int *array, size_t size, int value);
int adv_binary_search(int *array, size_t low, size_t high, int value);
void adv_print_array(int *array, size_t low, size_t high);
listint_t *jump_list(listint_t *list, size_t size, int value);


/*Helper Functions */
void free_list(listint_t *list);
listint_t *create_list(int *array, size_t size);
void print_list(const listint_t *list);








#endif /* SEARCH_ALGOS_H */
