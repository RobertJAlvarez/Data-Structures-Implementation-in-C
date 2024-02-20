#ifndef __ARRAYLIST_H__
#define __ARRAYLIST_H__

typedef struct {
  void **array;  // Array of pointers where each entry points to the data
  size_t __size;
  size_t len;
} ArrayList_t;

/* Initialize an array list of size 0.
 * Return pointer to ArrayList_t if successful, NULL otherwise.
 * Run time: O(1).
 */
ArrayList_t *AL_init(void);

/* Delete every data element in array and free the array.
 * Return 0 if everything was free successfully, 1 otherwise.
 * Run time: O(n).
 */
int AL_free(ArrayList_t *AL, int (*delete_data)(void *));

/* Print every element in AL->array.
 * Run time: O(n)
 */
void AL_print(ArrayList_t *AL, void (*print_data)(void *));

/* Retrieve the element i in AL->array.
 * Run time: O(1).
 */
void *AL_get_at(ArrayList_t *AL, size_t i);

/* Delete element i in AL->array and copy elem into it.
 * Run time: O(1).
 */
int AL_set_at(ArrayList_t *AL, size_t i, void *elem, void *(*copy_data)(void *),
              int (*delete_data)(void *));

/* Pre-append elem to AL->array.
 * Run time: O(1) amortize.
 */
int AL_insert_first(ArrayList_t *AL, void *elem, void *(*copy_data)(void *));

/* Delete first element in AL->array.
 * Run-time O(1) amortize.
 */
int AL_delete_first(ArrayList_t *AL, int (*delete_data)(void *));

/* Append elem to AL->array.
 * Run time: O(1) amortize.
 */
int AL_insert_last(ArrayList_t *AL, void *elem, void *(*copy_data)(void *));

/* Delete last element in AL->array.
 * Run time: O(1) amortize.
 */
int AL_delete_last(ArrayList_t *AL, int (*delete_data)(void *));

/* Insert elem at index i in AL.
 * Run time: O(n).
 */
int AL_insert_at(ArrayList_t *AL, size_t i, void *elem,
                 void *(*copy_data)(void *));

/* Delete the element at index i in AL.
 * Run time: O(n).
 */
int AL_delete_at(ArrayList_t *AL, size_t i, int (*delete_data)(void *));

#endif
