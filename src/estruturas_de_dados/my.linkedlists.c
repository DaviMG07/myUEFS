#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int value;
  struct node* next;
  struct node* prev;
} *node;


int printll(node);
int append(node*, int);
int push(node*, int);

/*TODO
int clear(node*); 
int insert(node*, int, int);  
int pop(node, int);
int search(node, int);
*/

int main(void){
  system("clear||cls");

  node head = NULL;

  append(&head, 10);
  append(&head, 20);
  push(&head, 8);
  //insert(&head, 7, 1);
  printll(head);
  printf("%d", clear(&head));

  printf("\n");
  return 0;
}

int printll(node head){
  if (head == NULL){
    printf("lista está vazia.");
    return 0;
  }
  node current = head;
  while (current != NULL){
    fflush(stdout);
    printf("%d ", current->value);
    current = current->next;
  }
  return 1;
}

int append(node* head, int value){
  node current;
  node new = (node)malloc(sizeof(node));
  new->value = value;
  new->next = NULL;

  if (*head == NULL){
    *head = new;
    return 0;
  }
  current = *head;
  while (current->next != NULL){
    current = current->next;
  }
  new->prev = current;
  current->next = new;
  return 1;
}

int push(node* head, int value){
  node new = (node)malloc(sizeof(node));
  new->value = value;
  new->next = NULL;
  new->prev = NULL;

  if (*head == NULL){
    *head = new;
    return 0;
  }
  node current = *head;

  new->next = current;
  current->prev = new;
  *head = new;
  return 1;
}


/*TODO
int clear(node* head){
  if (*head == NULL){
    return 0;
  }
  node current = *head;
  node next = current->next;
  while (current){
    current = next;
  }
  return 1;
}
*/
