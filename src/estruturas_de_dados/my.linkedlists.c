#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int value;
  struct node* next;
  struct node* prev;
} *node;


int printll(node);
int appendll(node*, int);

//TODO
int insert(node, int);
int push(node, int);
int pop(node, int);
int clear(node);
int search(node, int);

int main(void){
  system("clear||cls");

  node head = NULL;

  appendll(head, 10);
  printf("%d", head);
  printll(head);

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
    printf("%d", current->value);
    current = current->next;
  }
  return 1;
}

int appendll(node* head, int value){
  node new = (node)malloc(sizeof(node));
  new->value = value;
  new->next = NULL;
  if (*head == NULL){
    *head = new;
    printf("new\n");
    return 1;
  }
  return 0;
  /*
  node* current = *head;
  while (current->next != NULL){
    current = current->next;
  }
  current->next = new;
  return 1;
  */ 
}
