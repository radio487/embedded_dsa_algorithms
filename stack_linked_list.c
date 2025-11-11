/*
 * Heap allocation should be used with caution in embedded programming but it may be useful here and there.
 * Stack implementation using a NULL terminated linked list. Dummy node at head. Nodes allocated in the heap.
 */

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 20

struct node {
  struct node *next;
  int val;
};
// NULL return signals heap allocation failure
struct node *init_stack(void) {
  struct node *head= malloc(sizeof(struct node));
  
  // avoid NULL dereferencing
  if (head == NULL) {
    return NULL;
  }
  // dummy value
  head->val = -1;
  head->next = NULL;
  return head;
}
// free all stack, including dummy head node
void free_stack(struct node *head) {
  struct node *n;
  
  while (head != NULL) {
    n = head->next;
    free(head);
    head = n;
  }
}
bool stack_empty(struct node *head) {
  return head->next == NULL;
}
// false denotes heap allocation failure
bool stack_push(struct node *head, int val) {
  struct node *n = malloc(sizeof(struct node));
  
  if (n == NULL) {
    return false;
  }
  n->val = val;
  n->next = head->next;
  head->next = n;
  return true;
}
// false value indicates an empty stack
bool stack_pop(struct node *head, int *val) {
  struct node *n;

  if (stack_empty(head)) {
    return false;
  }
  else {
    n = head->next;
    *val = n->val;
    head->next = head->next->next;
    free(n);
    return true;
  }
}

int main() {
  struct node *head;
  int val;

  head = init_stack();
  if (head == NULL) {
    printf("malloc failed\n");
    return 1;
  }

  for (int i = 0; i < SIZE; ++i) {
    stack_push(head, i);
  }
  for (int i = 0; i < SIZE; ++i) {
    stack_pop(head, &val);
    printf("%d\n", val);
  }

  free_stack(head);
  return 0;
}
