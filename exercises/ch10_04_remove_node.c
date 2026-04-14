// This program removes a node from a linked list
#include <stdio.h>

struct node {
  int value;
  struct node *next;
};

void removeNode(struct node **head, struct node *rem);

int main(void) {
  struct node n1, n2, n3;
  struct node *head, *curr;

  head = &n1;

  n1.value = 100;
  n1.next = &n2;

  n2.value = 200;
  n2.next = &n3;

  n3.value = 300;
  n3.next = (struct node *)0;

  printf("Original list:\n");
  curr = head;
  while (curr) {
    printf("%i\n", curr->value);
    curr = curr->next;
  }

  removeNode(&head, &n2);
  printf("Remove inside list:\n");
  curr = head;
  while (curr) {
    printf("%i\n", curr->value);
    curr = curr->next;
  }

  removeNode(&head, &n1);
  printf("Remove head from list:\n");
  curr = head;
  while (curr) {
    printf("%i\n", curr->value);
    curr = curr->next;
  }

  return 0;
}

void removeNode(struct node **head, struct node *rem) {
  if (rem == *head) {
    *head = rem->next;
  } else {
    struct node *bef, *curr;
    bef = *head;
    curr = bef->next;

    while (curr) {
      if (curr == rem) {
        bef->next = curr->next;
        return;
      } else {
        bef = curr;
        curr = curr->next;
      }
    }
  }
}
