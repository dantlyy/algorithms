#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* hashTable[SIZE];

int hash(int key){ return key % SIZE; }

void insert(int key){
    int idx = hash(key);
    Node* newNode = malloc(sizeof(Node));
    newNode->key=key;
    newNode->next=hashTable[idx];
    hashTable[idx]=newNode;
}

void display(){
    for(int i=0;i<SIZE;i++){
        printf("%d:",i);
        Node* temp=hashTable[i];
        while(temp){ printf(" %d",temp->key); temp=temp->next;}
        printf("\n");
    }
}

int main(){
    insert(10); insert(20); insert(30); insert(15);
    display();
    return 0;
}
