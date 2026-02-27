#include <stdio.h>

#define SIZE 10
int hashTable[SIZE];

int hash(int key){ return key % SIZE; }

void insert(int key){
    int idx = hash(key);
    while(hashTable[idx]!=0) idx=(idx+1)%SIZE;
    hashTable[idx]=key;
}

void display(){
    for(int i=0;i<SIZE;i++) printf("%d ",hashTable[i]);
    printf("\n");
}

int main(){
    insert(10); insert(20); insert(30); insert(15);
    display();
    return 0;
}
