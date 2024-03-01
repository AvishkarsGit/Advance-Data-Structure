#include<iostream>
using namespace std;

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}node;


node *create(int data){
    node *n;
    n = (node*)malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return(n);
}
node *insert_general_tree(node *root,int value){
    if (root == NULL)
    {
        return create(value);
    }
    if (value <= root->data)
    {
        root->left = insert_general_tree(root->left,value);
    }
    else if(value > root->data) {
        root->right = insert_general_tree(root->right,value);
    }
    return root;
   
}
void inOrderTraversal(node *root){
    if (root != NULL) {
        inOrderTraversal(root->left);
        cout<<root->data<<"->";
        inOrderTraversal(root->right);
    }
}
void convert_binary(){
    
}
int main()
{
    node *root=NULL;
    int n,x;
    char choice;
    do{
        cout<<"\nEnter node element to insert into tree :";
        cin>>x;
        root = insert_general_tree(root,x);


        cout<<"\nDo you want to add another node:(y/n):";
        cin>>choice;


    }while(choice == 'y' || choice == 'Y');
    cout<<"\nIn order :";
    inOrderTraversal(root);
    return 0;
}