#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{   // Store all kinds of data types
    char item[20];
    int priority;
    struct Node *next;
};

void dequeue(struct Node ** list);
void equeue(struct Node ** list, char *data, int pri);
struct Node* peek(struct Node * list);
void display(struct Node * list);

struct Node * new_node(char * data, int pri)
{
    struct Node * n = malloc(sizeof(struct Node));
    strcpy(n->item,data);
    n->priority = pri;
    n->next = NULL;
    return n;
}

//ok
void dequeue(struct Node **list){
   //The list only has no node
   if ( list == NULL ){
       printf("Can't remove from empty Queue.\n");
   }
   //The list only has one node
   else if ( (*list)->next == NULL ) {
       list = NULL;
   }
   else {
       struct Node* curr = *list;
       *list = (*list)->next;
       free(curr);
   }
}
//ok
void equeue(struct Node ** list, char *data, int pri)
{
  //make a new node to store data
  struct Node * new_Nd = new_node(data, pri);

  if( *list == NULL ) {
      *list = new_Nd;

  }//Special case: New node has the largest prioriity
  else if ( (*list)->priority > new_Nd->priority )
  {
      new_Nd->next = *list;
      *list = new_Nd;
  }// general case
  else {
      struct Node* curr = *list;
      while ( curr->next != NULL && pri >= curr->next->priority ) {
         curr = curr->next;
      }
      new_Nd->next = curr->next;
      curr->next = new_Nd;

  }

}
struct Node* peek(struct Node * list) {
    if ( list == NULL ) {
        printf("The Queue is empty. Can't peek.\n");
    }
    struct Node * curr = list;
    return curr;
}
//ok
void display(struct Node * list) {
    if (list == NULL){
        printf("The list is empty.\n");
    } else {
        struct Node * curr = list;
        while ( curr != NULL)
        {
            printf("Node:");
            printf("%s->",curr->item);
            printf("priority %d\n", curr->priority);
            curr = curr->next;
        }
    }
}

//test, remove code once it's done
int main(void){
  struct Node * list;
  int choice,priority;
  equeue(&list,"test",4);
  equeue(&list,"test",5);
  equeue(&list,"test-1",5);
  equeue(&list,"test",1);
  equeue(&list,"test-1",6);
  equeue(&list,"test",7);
  equeue(&list,"test-1",6);
  equeue(&list,"test",4);
  dequeue(&list);
  dequeue(&list);
  dequeue(&list);
  printf("%s %d\n",peek(list)->item,peek(list)->priority);
  display(list);
  char item[20];

 return 0;
}
