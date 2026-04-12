// This program will insert a node at a specified point in a linked list
#include <stdio.h>

struct node {
  int value;
  struct node *next;
};

void insertNodeAfter(struct node *entry, struct node *i_point);
void insertNodeBefore(struct node *entry, struct node *i_point,
                      struct node **head);

int main(void) {
  struct node n1, n2, n3, n4;
  struct node *head, *curr, *ins;

  head = &n1;

  n1.value = 100;
  n1.next = &n2;

  n2.value = 200;
  n2.next = &n4;

  n4.value = 400;
  n4.next = (struct node *)0;

  n3.value = 300;

  curr = head;
  printf("Before insertion:\n");
  while (curr) {
    printf("val: %i\n", curr->value);
    curr = curr->next;
  }

  curr = &n3;
  ins = &n2;
  insertNodeBefore(curr, ins, &head);
  curr = head;
  printf("After insertion:\n");
  while (curr) {
    printf("val: %i\n", curr->value);
    curr = curr->next;
  }

  return 0;
}

void insertNodeAfter(struct node *entry, struct node *i_point) {
  if (i_point != 0) {
    entry->next = i_point->next;
    i_point->next = entry;
  }
}

void insertNodeBefore(struct node *entry, struct node *i_point,
                      struct node **head) {
  if (i_point == *head) {
    entry->next = *head;
    *head = entry;
  } else {
    struct node *bef, *curr;
    curr = (*head)->next;
    bef = *head;

    while (curr) {
      if (curr == i_point) {
        bef->next = entry;
        entry->next = curr;
        return;
      } else {
        bef = curr;
        curr = curr->next;
      }
    }
  }
}
