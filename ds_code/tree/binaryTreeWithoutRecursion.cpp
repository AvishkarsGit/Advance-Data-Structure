#include<iostream>
#include<stack>
using namespace std;

typedef struct node {
    int data;
    struct node *left, *right;
}node;

node *create(int data){
    node *n;
    n = (node*) malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return(n);
}

void preOrderTraversal(node *root){
    if (root == nullptr)
        return;

    stack<node*> st;
    st.push(root);
    while (!st.empty()) {
        node* temp = st.top();
        st.pop();
        cout << temp->data << "->";
        if (temp->right != nullptr)
            st.push(temp->right);
        if (temp->left != nullptr)
            st.push(temp->left);
    }
    
}

void inOrderTraversal(node *root){
    if(root == NULL){
        return;
    }
    stack<node*> st;
    node *temp = root;
    while(!st.empty()|| temp!=NULL){
        if(temp!=NULL){
            st.push(temp);
            temp = temp->left;
        }
        else {
            temp = st.top();
            st.pop();
            cout<<temp->data<<"->";
            temp = temp->right;
        }
    }
}

void postOrderTraversal(node *root){
    stack<node*> st;
    node* current = root;
    while(current!=NULL || !st.empty()){
        if(current!=NULL){
            st.push(current);
            current = current->left;
        }
        else {
            node *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                cout<<temp->data<<"->";
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    cout<<temp->data<<"->";
                }
            }
            else{
                current = temp;
            }
            
        
        }
    }
}
int main(){

    node* root = create(10);
    node* first = create(20);
    node* second = create(30);
    node* third = create(40);
    node* fourth = create(50);
    node* fifth = create(60);
    node* sixth = create(70);
    node* seventh = create(80);

    root->left = first;
    root->right = second;
    first->left = third;
    first->right = fourth;
    second->left = fifth;
    second->right = sixth;
    third->left = seventh;

    /*
                  10 
                /   \
              20     30
             /  \   /  \
            40  50 60   70
            preorder = 10,20,40,50,30,60,70

    */
     
    cout<<"\nPre-Order Traversal:\n";
    preOrderTraversal(root);
    cout<<"\nin-Order Traversal:\n";
    inOrderTraversal(root);
    cout<<"\nPost-Order Traversal:\n";
    postOrderTraversal(root);
    
    return 0;
}
