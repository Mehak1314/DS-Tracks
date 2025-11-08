#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
node* createtree(node* root)
{
    int data;
    cout<<"Enter data: ";
    cin>>data;
    if(data==-1){
        return NULL;
    }
    root=new node(data);
    cout<<"Enter left data of "<<data<<endl;
    root->left=createtree(root->left);
    cout<<"Enter right data of "<<data<<endl;
    root->right=createtree(root->right);
    return root;
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node* root){
    if(root==NULL){
        return;
    }
    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<" ";
}
void postorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    postorder(root->left);
    postorder(root->right);

}
int main(){
    node* root=NULL;
    root =createtree(root);
    cout<<"Inorder: "<<endl;
    inorder(root);
    cout<<"\nPreorder: "<<endl;
    preorder(root);
    cout<<"\nPostorder: "<<endl;
    postorder(root);
    return 0;
}
