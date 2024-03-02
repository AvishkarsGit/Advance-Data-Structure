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

void printTabs(int numtabs){
    for(int i = 0;i<numtabs;i++){
        cout<<"\t";
    }
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

// Function to print spaces
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

int main()
{
    /*
           10
          /  \
        20    30
       / \   /  \
      40 50 60  70
    */
    node *n1 = create(1);
    node *n2 = create(2);
    node *n3 = create(3);
    node *n4 = create(4);
    node *n5 = create(5);
    node *n6 = create(6);
    node *n7 = create(7);
    
    // link
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;


    cout<<"****** Your generated binary tree ******\n";
    printTree(n1,0);
    cout<<"\n***** Pre Order Traversal **********\n";
    preOrderTraversal(n1);
    cout<<"\n***** In Order Traversal **********\n";
    inOrderTraversal(n1);
    cout<<"\n***** Post Order Traversal **********\n";
    postOrderTraversal(n1);
    cout<<"\n";
    return 0;
}