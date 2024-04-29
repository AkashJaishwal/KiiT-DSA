// Write a program in C to create a linked list to receive your name as input and display the list and delete vowels from list and display it.

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

struct Node 
{ 
  char name; 
  struct Node* next; 
}; 

void push(struct Node** head_ref, char new_name) 
{ 
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
  new_node->name = new_name; 
  new_node->next = (*head_ref); 
  (*head_ref) = new_node; 
} 

void printList(struct Node *head) 
{ 
  struct Node *temp = head; 
  while(temp != NULL) 
  { 
    printf("%c ",temp->name); 
    temp = temp->next; 
  } 
} 


void deleteVowels(struct Node *head) 
{ 
  struct Node *temp = head; 
  struct Node* prev; 

  if (temp != NULL && (temp->name=='a' || temp->name=='A' || temp->name=='e' || temp->name=='E' || temp->name=='i' || temp->name=='I' || temp->name=='o' || temp->name=='O' || temp->name=='u' || temp->name=='U')) 
  { 
    head = temp->next; 
    free(temp); 
    deleteVowels(head); 
  } 

  while (temp!=NULL) 
  { 

    if (temp->name=='a' || temp->name=='A' || temp->name=='e' || temp->name=='E' || temp->name=='i' || temp->name=='I' || temp->name=='o' || temp->name=='O' || temp->name=='u' || temp->name=='U') 
    { 
      prev->next = temp->next; 
      free(temp); 
      temp = prev->next; 
    } 
    else
    { 
      prev = temp; 
      temp = temp->next; 
    } 
  } 
} 

int main() 
{ 
    system("cls");
  struct Node* head = NULL; 
    char str[100];
    int len,i;
    printf("\nEnter Your Name : ");
    gets(str);
    len=strlen(str);
    for(i=0;i<len;i++)
    {
        push(&head,str[i]);
    }
  printList(head);
  deleteVowels(head); 
  printf("\nAfter Vowel Removal : "); 
  printList(head); 
  return(0); 
}A