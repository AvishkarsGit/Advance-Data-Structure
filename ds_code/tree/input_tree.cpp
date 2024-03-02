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
void preOrderTraversal(node *root)
{
    
    if (root == NULL)
    {
        return;
    }
    cout<<root->data<<"->";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(node *root){
    if (root == NULL)
    {
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<"->";
    inOrderTraversal(root->right);
}
void postOrderTraversal(node *root)
{
    if(root == NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<"->";
}

void printSpaces(int n) {
    for (int i = 0; i < n; i++)
        printf(" ");
}

// Function to print the tree nodes in the specified pattern
void printTree(node* root, int space) {
    // Base case
    if (root == NULL)
        return;
    
    // Increase distance between levels
    space += 5;

    // Process right child first
    printTree(root->right, space);
    
    // Print current node after space
    printf("\n");
    printSpaces(space);
    printf("%d", root->data);

    // Process left child
    printTree(root->left, space);
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
    cout<<"****** Your generated binary tree ******\n";
    printTree(root,0);
    cout<<"\n***** Pre Order Traversal **********\n";
    preOrderTraversal(root);
    cout<<"\n***** In Order Traversal **********\n";
    inOrderTraversal(root);
    cout<<"\n***** Post Order Traversal **********\n";
    postOrderTraversal(root);
    cout<<"\n";
    return 0;
}