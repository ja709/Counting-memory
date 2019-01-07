#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000

typedef struct Node{
  char address[30];
  long val;
  struct Node *next;
}Node;

struct Node *hashtable[SIZE] = {NULL};

void insert(Node *h, Node *newNode){
  
  //printf("%s\n", newNode->address);
  long add = strtol(newNode->address, NULL, 16);
  //printf("%ld\n", add);
  int index = add % SIZE;
  //printf("%d\n", index);
  
  int i, check = 0;
  struct Node *temp = malloc(sizeof(Node));
  //temp = hashtable[index];
  //printf("%ld\n", temp->val);
  //printf("%ld\n", add);
  
  for(i = 0; i< SIZE; i++){
    for(temp = hashtable[index]; temp != NULL; temp = temp -> next){
      if(temp -> val == add){
    	check = 1;
    	return;
      }
    }
  }
  
  if(check == 0){
    struct Node *temp = malloc(sizeof(Node));
    temp -> val = add;
    temp -> next = hashtable[index];
    hashtable[index] = temp;
  }

}

void display(int k){
	int count = 0;
	for(k = 0 ; k < SIZE; k++){
	  if(hashtable[k] == NULL){
    }else{ 
		struct Node *temp = malloc(sizeof(Node));	
      for(temp=hashtable[k];temp!=NULL;temp=temp->next){
				count++;
			}
  	}
	}
	if(count == 1){
		printf("0\n");
		return;
	}
	printf("%d\n", count);
}

int getIndex(int a){
  return (a % SIZE);
}

int main (int argc, char *argv[]){
  FILE *fp = NULL;
  char *filename = NULL;
  char unique_address[30];
  int i;
  long add;
  struct Node* head = NULL;
  filename = argv[1];
  fp = fopen(filename, "r");
  
  if(fp == NULL){
    printf("error\n");
    return 0;
  }
  
  while(!feof(fp)){
    
    fscanf(fp, "%s\n", unique_address);
    add = strtol(unique_address, NULL, 16);
    i = getIndex(add);
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    strcpy(newNode->address, unique_address);
    insert(head, newNode);
    
  }
	display(i);
  return 0;
}
