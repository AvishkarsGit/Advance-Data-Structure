#include<iostream>
#include<string.h>
using namespace std;

typedef struct node{
    string chapter_name;
    string section_name;
    string subsection_name;
    int chapter_no;
    int section_no;
    int subsection_no;
    struct node *left;
    struct node *right;
}node;

node *create(){
    node *root;
    root = (node*)malloc(sizeof(node));
    root->left = NULL;
    root->right = NULL;
    root->chapter_name = "";
    root->section_name = "";
    root->subsection_name = "";
    root->chapter_no = 0;
    root->section_no = 0;
    root->subsection_no = 0;

    return root;
}

node *insert(node *root,string chapter_name, int chapter_no){
    if (root == NULL)
    {
        return create();
    }
    
    root->chapter_name = chapter_name;
    root->chapter_no = chapter_no;
    return (root);  
}

node *insert_section(node *root,string section_name,int section_no){
    if (root == NULL)
    {
        return create();
    }
    
    
}
int main()
{
    cout<<"\nEnter Chapter Name:";
    return 0;
}