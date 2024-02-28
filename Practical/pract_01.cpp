#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define table_size 10

typedef struct node{
    string phoneNo;
    string name;
    string address;
    struct node *next;
}node;

node *hashTable[table_size];

node *create(string name,string phoneNo,string address){
    node *newNode;
    newNode =(node*)malloc(sizeof(node));
    newNode->name = name;
    newNode->phoneNo = phoneNo;
    newNode->address = address;
    newNode->next = NULL;
    return(newNode);
}
int getHashValue(string name){
    int c,sum=0;
    for (int i = 0; i < name.length(); i++)
    {
        c = name[i];
        sum = sum + c;
    }
    return sum % table_size;
}
void init(){
    for (int i = 0; i < table_size; i++)
    {
        hashTable[i] = NULL;
    }
    
}
void add(){
    node *n;
    string phoneNo,name,address;
    cout<<"\nEnter Phone No:";
    cin>>phoneNo;
    cout<<"\nEnter Name :";
    cin>>name;
    cout<<"\nEnter address:";
    cin>>address;
    n = create(name,phoneNo,address);
    int index = getHashValue(name);
    if(hashTable[index] == NULL){
        hashTable[index] = n;
    }
    else {
        node *temp = hashTable[index];
        while (temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
    cout<<"\nRecorded Inserted...";
}
void display(){
    node *n1;
    for (int i = 1; i < table_size; i++)
    {
        if (hashTable[i] == NULL)
        {
            continue;
        }
        else {
            for (n1 = hashTable[i]; n1!=NULL; n1=n1->next)
            {
                if (n1->name.length()<8)
                {
                    cout<<hashTable[i]->name<<"\t\t"<<hashTable[i]->phoneNo<<"\t"<<hashTable[i]->address<<"\n";
                }
                else {
                    cout<<hashTable[i]->name<<"\t"<<hashTable[i]->phoneNo<<"\t"<<hashTable[i]->address<<"\n";
                }            
            }
        }
    }   
}

void search(){
    node *n;
    string name;
    cout<<"\nEnter name to search record :";
    cin>>name;
    int index = getHashValue(name);
    for (n = hashTable[index]; n!=NULL;n=n->next)
    {
        if (n->name == name)
        {
            cout<<"\n******* RECORD *********";
            cout<<"\nName:"<<n->name;
            cout<<"\nPhoneNo:"<<n->phoneNo;
            cout<<"\nAddress:"<<n->address;
        }
        else {
            cout<<"\nRecord doesn't exist";
        }
    }
}

void remove(){
    node *n,*n1;
    int index;
    string name;
    cout<<"\nEnter name to delete :";
    cin>>name;
    index = getHashValue(name);
    if (hashTable[index]->name == name)
    {
        n = hashTable[index];
        hashTable[index] = hashTable[index]->next;
        free(n);
        return;
    }
    for (n = hashTable[index]; n->next!=NULL;n=n->next)
    {
        n1 = n->next;
        if (n1->name == name)
        {
            n->next = n1->next;
            free(n1);
            break;
        }   
        else {
            cout<<"\nRecord doesn't exist!";
        }
    }

}
int main(){
    
    int choice;
    init();
    do
    {
        cout<<"\n****TELEPHONE DIRECTORY ****";
        cout<<"\n1.Add Contact";
        cout<<"\n2.Search Contact";
        cout<<"\n3.Print Contact list";
        cout<<"\n4.Delete Contact";
        cout<<"\n5.Exit";
        cout<<"\nEnter your choice:";
        cin>>choice;
        switch (choice)
        {
            case 1:
            add();
            break;  
       
            case 2:
            search();
            break;  
       
            case 3:
            display();
            break;
            
            case 4:
            remove();
            display();
            break;

            case 5:
            break;  
        
         
       
            default:
                break;
        }
        
    } while (choice!=5);
    
    return 0;
}