// This program does the basic implementation of a doubly linked list
#include <stdio.h>

struct node {
  int value;
  struct node *prev;
  struct node *next;
};

void printList(struct node *head);
void insertNode(struct node **head, struct node *ins, struct node *new);
void removeNode(struct node **head, struct node *target);

int main(void) {
  struct node n1, n2, n3, n4;
  struct node *head, *curr;

  head = &n1;

  n1.value = 100;
  n1.prev = (struct node *)0;
  n1.next = &n2;

  n2.value = 200;
  n2.prev = &n1;
  n2.next = &n3;

  n3.value = 300;
  n3.prev = &n2;
  n3.next = (struct node *)0;

  n4.value = 400;

  printf("Original list:\n");
  printList(head);

  curr = &n4;
  insertNode(&head, &n1, curr);
  printf("\nAfter insertion:\n");
  printList(head);

  curr = &n4;
  removeNode(&head, curr);
  printf("\nAfter removal:\n");
  printList(head);

  return 0;
}

void printList(struct node *head) {
  while (head) {
    printf("%i\n", head->value);
    head = head->next;
  }
}

void insertNode(struct node **head, struct node *ins, struct node *new) {
  if (ins == *head) {
    new->prev = (struct node *)0;
    new->next = *head;
    *head = new;
    ins->prev = new;
  } else {
    struct node *bef = ins->prev;
    bef->next = new;
    new->prev = ins->prev;
    new->next = ins;
    ins->prev = new;
  }
}

void removeNode(struct node **head, struct node *target) {
  if (target == *head) {
    struct node *new = (*head)->next;
    *head = new;
    new->prev = (struct node *)0;
  } else {
    struct node *bef = target->prev;
    struct node *after = target->next;
    bef->next = target->next;

    if (after != 0)
      after->prev = bef;
  }
}
