//pract 02
#include<iostream>
#include<stdlib.h>
using namespace std;
#define table_size 10


typedef struct node{
    int key;
    char value[256];
    struct node *next;
}node;

node *hashTable[table_size];

node *create(int key, char value[]){
    node *head;
    head =(node)malloc(sizeof(node*));
    head->key = key;
    head->value = value;
    head->next = NULL;
    return(head);
}
int getBucketIndex(int key){
    int index = key % table_size;
    return index;
}
void insert(int key,char value[]){
    node *head;
    head = create(key,value);
    int bucketIndex = getBucketIndex(key);
    if (hashTable[bucketIndex]==NULL){
        hashTable[bucketIndex] = head;
    }
    else {
        node *temp = hashTable[bucketIndex];
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = head;
    }
}
void print(){
    for (int i=0;i<table_size;i++){
        node *p = hashTable[i];
        cout<<hashTable[i]<<"->";
        while(p){
            cout<<p->value<<"->";
        }
        cout<<"NULL\n";
    }
}
void initialize()
{
    for (int i =0;i<table_size;i++){
        hashTable[i] = NULL;
    }
}
int main(){

    initialize();
    int choice;

    do {

        cout<<"*** Dictionary operations ***";
        cout<<"\n1.Insert";
        cout<<"\n2.Find";
        cout<<"\n3.Delete";
        cout<<"\n4.Exit";
        cout<<"\nEnter your choice:";
        cin>>choice;
        switch(choice){

            case 1: 
                insert(45,"ganesh");       
                break;

            case 2: 
                print();
                break;
            case 3: 
                break;
            case 4: 
                break;

            default:
                cout<<"\nInvalid choice";
            break;
        }
    }while(choice!=4);
    return 0;
}