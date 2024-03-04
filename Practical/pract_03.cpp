#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define MAX 256
typedef struct book{
    string  data;
    struct book *firstChild;
    struct book *nextSibling;
}node;

node *create(string data)
{
    node *root;
    root = (node*)malloc(sizeof(node));
    if(root == NULL){
        exit(1);
    }    
    root->data = data;
    root->firstChild = NULL;
    root->nextSibling = NULL;
    return root;
}

void insert(node *parent, node *child){

    if(parent->firstChild == NULL){
        parent->firstChild = child;
    }
    else {
        node *current = parent->firstChild;
        while(current->nextSibling!= NULL){
            current = current->nextSibling;
        }
        current->nextSibling = child;
    }
}

void print(node *root,int depth){
    if(root != NULL){
        for (int i =0 ;i<depth;i++){
            cout<<"-\t";
        }
        cout<<root->data<<endl;
        print(root->firstChild,depth+1);
        print(root->nextSibling,depth);
    }

}

int main()
{
   
    node* book = create("Advance Data Strucutre");
    
    //chapter 1
    node* chapter1 = create("1. Hashing");
    node* chapter2 = create("2. Tree");
    insert(book, chapter1);
    insert(book, chapter2);
    
    node* section1_1 = create("1.1 Concept of Hashing");
    node* section1_2 = create("1.2 Extendible Hashing");
    node* section1_3 = create("1.3 Skip List");
    insert(chapter1, section1_1);
    insert(chapter1, section1_2);
    insert(chapter1, section1_3);
        
    node* subsection1_1_1 = create("1.1.1 Overview Of Hashing");
    node* subsection1_1_2 = create("1.1.2 Hash Functions");
    node* subsection1_1_3 = create("1.1.3 Collision");
    node* subsection1_1_4 = create("1.1.4 Collision Handling");
    insert(section1_1, subsection1_1_1);
    insert(section1_1, subsection1_1_2);
    insert(section1_1, subsection1_1_3);
    insert(section1_1, subsection1_1_4);

    node* subsection1_2_1 = create("1.2.1 Concept");
    node* subsection1_2_2 = create("1.2.2 Implementation");
    insert(section1_2, subsection1_2_1);
    insert(section1_2, subsection1_2_2);

    node* subsection1_3_1 = create("1.3.1 Insertion");
    node* subsection1_3_2 = create("1.3.1 Deletion");
    node* subsection1_3_3 = create("1.3.3 Searching");
    insert(section1_3, subsection1_3_1);
    insert(section1_3, subsection1_3_2);
    insert(section1_3, subsection1_3_3);


    // chapter 2
    node* section2_1 = create("2.1 Tree Terminology");
    node* section2_2 = create("2.2 Binary Tree");
    node* section2_3 = create("2.3 Binary Search Tree");
    insert(chapter2, section2_1);
    insert(chapter2, section2_2);
    insert(chapter2, section2_3);

    node* subsection2_1_1 = create("2.1.1 Root ");
    node* subsection2_1_2 = create("2.1.2 Leaf");
    node* subsection2_1_3 = create("2.1.3 Traversal");
    insert(section2_1, subsection2_1_1);
    insert(section2_1, subsection2_1_2);
    insert(section2_1, subsection2_1_3);

    
    node* subsection2_2_1 = create("2.2.1 Convert tree to binary tree ");
    node* subsection2_2_2 = create("2.2.2 Tree Traversal");
    node* subsection2_2_3 = create("2.2.3 DFS and BFS");
    insert(section2_2, subsection2_2_1);
    insert(section2_2, subsection2_2_2);
    insert(section2_2, subsection2_2_3);

    print(book, 0);



    return 0;
}