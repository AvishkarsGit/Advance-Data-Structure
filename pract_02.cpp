//pract 02
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define table_size 10


typedef struct node{
    int key;
    string value;
    struct node *next;
}node;

node *hashTable[table_size];

node *create(int key, string name){
    node *head;
   
    head = (node*)malloc(sizeof(node));
    head->key = key;
    head->value = name;
    head->next = NULL;
    return(head);
}
int getBucketIndex(int key){
    int index = key % table_size;
    return index;
}
void insert(int key,string value){
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
    cout<<"\nInserted...";
}
void print(){
    node *n1;
    for (int i = 0; i < table_size; i++)
    {
        cout<<"\n["<<i<<"]\t";
        if (hashTable[i]==NULL){
            continue;
        }
        else{
            for (n1 = hashTable[i]; n1!=NULL;n1=n1->next)
            {
                cout<<"["<<n1->key<<"|"<<n1->value<<"]->";            
            }
            
        }
        
    }
}
void find(int key){
    int index;
    node *n1;
    index = getBucketIndex(key);
    if (hashTable[index]==NULL){
        cout<<"\nElement not found!";
    }
    else {
        for (n1 = hashTable[index];n1!=NULL;n1=n1->next)
        {
            if (n1->key == key)
            {
                cout<<"\nelement is found at index "<<index;
                break;
            }
        }
        if (n1==NULL)
        {
            cout<<"\nElement is not found!!";
        }   
    }
}
void remove(int key){
    
    node *n,*n1;
    int index;
    index = getBucketIndex(key);
    if (hashTable[index]->key == key)
    {
        n = hashTable[index];
        hashTable[index] = hashTable[index]->next;
        free(n);
        return;
    }
    for (n = hashTable[index]; n->next!=NULL;n=n->next)
    {
        n1 = n->next;
        if (n1->key,key)
        {
            n->next = n1->next;
            free(n1);
            break;
        }
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
    int key;
    string value;

    do {

        cout<<"\n\n*** Dictionary operations ***";
        cout<<"\n1.Insert";
        cout<<"\n2.Print";
        cout<<"\n3.Find";
        cout<<"\n4.Delete";
        cout<<"\n5.Exit";
        cout<<"\nEnter your choice:";
        cin>>choice;
        switch(choice){

            case 1: 
                cout<<"\nEnter key:";
                cin>>key;
                cout<<"\nEnter value:";
                cin>>value;
                insert(key,value);
                break;

            case 2: 
                print();
                break;
            case 3: 
                cout<<"\nEnter key to find: ";
                cin>>key;
                find(key);
                break;
            case 4: 
                cout<<"\nEnter key to find: ";
                cin>>key;
                remove(key);
                break;
            case 5: 
                break;
            default:
                cout<<"\nInvalid choice";
            break;
        }
    }while(choice!=5);
    return 0;
}