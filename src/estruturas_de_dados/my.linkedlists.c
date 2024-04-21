#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int value;
  struct node* next;
  struct node* prev;
} *node;

//print the linked list
void printll(node);

//return the index of first occurrence of given value, if not found, return -1
int search(node, int);

//return number of nodes in a linked list 
int len(node);

//insert node in the end of linked list (doubly linked list without tail)
void append(node*, int);

//insert node in the beginning of linked list (doubly linked list)
void push(node*, int);

//insert node at given position
void insert(node*, int, int);

//delete node by index (doubly linked list without tail)
void delete(node*, int);

//delete all nodes in linked list 
void clear(node*);

/*TODO
* copy linked list
* node copy(node);
*
* return the adress of first occurrence of given value 
* node searchN(node, int);
*/

int main(void){
  system("cls||clear");

  node head = NULL;

  int i = 1;

  printf("------------------------start------------------------\n");
  printll(head);

  printf("\nappend\n");
  append(&head, 0);
  printll(head);

  printf("\nappend\n");
  append(&head, 2);
  printll(head);

  printf("\nappend\n");
  append(&head, 3);
  printll(head);

  printf("\nlength of linked list\n");
  printf("%d\n", len(head));

  printf("\ninsert at index %d\n", i);
  insert(&head, i, 1);
  printll(head);

  printf("\npush\n");
  push(&head, -1);
  printll(head);

  printf("\ndelete at index 0\n");
  delete(&head, 0);
  printll(head);

  printf("\nsearch position of number 3\n", search(head, 1));
  printf("%d\n", search(head, 3));

  printf("\nclear\n");
  clear(&head);
  printll(head);

  printf("\n------------------------end------------------------\n");
  printll(head);
  printf("---------------------------------------------------\n");

  printf("\n");
  return 0;
}

void printll(node head){
  printf("NULL -> ");
  while (head){
    printf("%d -> ", head->value);
    head = head->next;
  }
  printf("NULL\n");
}

void append(node* head, int value){
  node new = (node)malloc(sizeof(node));
  new->value = value;
  new->next = NULL;
  new->prev = NULL;

  if (*head == NULL){
    *head = new;
    return;
  }
  node current = *head;

  while (current){
    if (current->next == NULL){
      current->next = new;
      new->prev = current;
      return;
    }
    current = current->next;
  }
}

void push(node* head, int value){
  node new = (node)malloc(sizeof(node));
  new->value = value;
  new->next = NULL;
  new->prev = NULL;

  if (*head == NULL){
    *head = new;
    return;
  }

  new->next = *head;
  (*head)->prev = new;
  *head = new;
}

void insert(node* head, int index, int value){
  node new = (node)malloc(sizeof(node));
  new->value = value;
  new->next = NULL;
  new->prev = NULL;

  if (*head == NULL){
    *head = new;
    return;
  }

  int counter = 0;
  node current = *head;
  if (!index){
    push(head, value);
    return;
  }
  while (current->next && counter < index - 1){
    ++counter;
    current = current->next;
  }
  new->next = current->next;
  new->prev = current;
  current->next = new;
}

int search(node head, int value){
  int counter = 0;
  while (head){
    if ((head)->value == value){
      return counter;
    }
    ++counter;
    head = (head)->next;
  }
  return -1;
}

int len(node head){
  int counter = 0;
  while (head){
    ++counter;
    head = (head)->next;
  }
  return counter;
}

void delete(node* head, int index){
  int counter = 0;
  node current = *head;

  while (current){
    if (counter == index){
      if (current->prev != NULL){
        current->prev->next = current->next;
      } else {
        *head = current->next;
      }
      if (current->next != NULL){
        current->next->prev = current->prev;
      }
      if (current == *head){
        *head = current->next;
      }
      free(current);
      return;
    }
    ++counter;
    current = current->next;
  }
}

void clear(node* head){
  node current = *head;
  while (*head){
    current = *head;
    *head = current->next;
    free(current);
  }
}

