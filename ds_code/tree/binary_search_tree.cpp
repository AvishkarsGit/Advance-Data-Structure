#include<iostream>
using namespace std;

typedef struct node {
    int data;
    struct node *left,*right;
}node;

node *create(int data){
    node *n;
    n = (node*)malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return(n);
}
node *createTree(node *root,int val){
    if (root == NULL) {
        root = create(val);
        return root;
    }
    if (val < root->data)
    {
        root->left = createTree(root->left,val);
    }
    if (val > root->data){
        root->right = createTree(root->right, val);
    }
    return root;
    
}
void inOrderTraversal(node *root){
    if (root == NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}
int main()
{
    int choice;
    char choose;
    node *root;
    do {

        cout<<"\n********* BST Operations ********** ";
        cout<<"\n1.CREATE TREE";
        cout<<"\n2.INSERT NODE";
        cout<<"\n3.DELETE NODE";
        cout<<"\n4.TRAVERSAL";
        cout<<"\n5.EXIT";
        cout<<"\nEnter Your choice:";
        cin>>choice;
        switch (choice)
        {
            case 1:
                do{
                    int x;
                    cout<<"\nEnter node element to insert into tree :";
                    cin>>x;
                    root = createTree(root,x);


                    cout<<"\nDo you want to add another node:(y/n):";
                    cin>>choose;
                }while(choose == 'y' || choose == 'Y');
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                inOrderTraversal(root);
                break;
            case 5:
                cout<<"\nThanks";
                break;
            default:
                cout<<"\nEnter valid choice";
        }
    }while (choice!=5);

    

    return 0;
}