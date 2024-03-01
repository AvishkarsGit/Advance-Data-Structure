#include<iostream>
using namespace std;

typedef struct node{
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
node *insert(node *root,int data){
    if (root == NULL)
    {
        root = create(data);
        return root;
    }

    if (data < root->data)
    {
        root->left = insert(root->left,data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right,data);
    }

    return root;
}
void preOrderTraversal(node *root){
    if (root!=NULL)
    {
        cout<<root->data<<"->";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
    
}
void inOrderTraversal(node *root){
    if (root != NULL) {
        inOrderTraversal(root->left);
        cout<<root->data<<"->";
        inOrderTraversal(root->right);
    }
}
void postOrderTraversal(node *root){
    if (root !=NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout<<root->data<<"->";
    }
}
int main(){

    node *root=NULL;
    int n,x;
    char choice;
    do{
        cout<<"\nEnter node element to insert into tree :";
        cin>>x;
        root = insert(root,x);


        cout<<"\nDo you want to add another node:(y/n):";
        cin>>choice;


    }while(choice == 'y' || choice == 'Y');
    preOrderTraversal(root);
    cout<<"\n\n";
    inOrderTraversal(root);
    cout<<"\n\n";
    postOrderTraversal(root);
    return 0;
}