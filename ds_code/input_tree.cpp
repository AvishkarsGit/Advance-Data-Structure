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
node *insert(int value){
    node *root;
    root = create(value);
    if (root == NULL)
    {
        return root;
    }

    if (value < root->data)
    {
        root->left = create(value);
    }
    else if (value > root->data)
    {
        root->right = create(value);
    }

    return root;
}
int main(){

    node *root;
    int n,x;
    cout<<"\nHow much nodes do you wants to add:";
    cin>>n;
    for (int i = 0; i<n;i++){
        if(i == 0){
            cout<<"\nEnter root node:";
            cin>>x;
            root = insert(x);     
        }
        else {
            cout<<"\nEnter child "<<(i+1)<<" :";\
            cin>>x;
            root = insert(x);
        }
    }
    
    return 0;
}