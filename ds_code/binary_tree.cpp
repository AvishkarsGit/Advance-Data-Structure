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

void preOrderTraversal(node *root){
    if (root!=NULL)
    {
        cout<<root->data<<"->";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);

    }
}
void postOrderTraversal(node *root){
    if (root!=NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout<<root->data<<"->";
    }
}
void inOrderTraversal(node *root){
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        cout<<root->data<<"->";
        inOrderTraversal(root->right);
    }
}

int main()
{
    /*
           10
          /  \
        20    30
       / \   /  \
      40 50 60  70
    */
    node *n1 = create(10);
    node *n2 = create(20);
    node *n3 = create(30);
    node *n4 = create(40);
    node *n5 = create(50);
    node *n6 = create(60);
    node *n7 = create(70);
    
    // link
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;

    cout<<"\n*** Pre-Order Traversal ***\n";
    preOrderTraversal(n1);
    cout<<"\n";
    cout<<"\n*** Post-Order Traversal ***\n";
    postOrderTraversal(n1);
    cout<<"\n";
    cout<<"\n*** In-Order Traversal ***\n";
    inOrderTraversal(n1);
    cout<<"\n";
    return 0;
}