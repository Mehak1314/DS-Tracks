//Minimum elemnt in bst
#include<iostream>
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
int min(node* root){
    if(root==NULL){
        cout<<"Empty"<<endl;
    }
    node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}
int main(){
    node* root=NULL;
    root=createtree(root);
    int mini=min(root);
    cout<<mini<<" is min element"<<endl;
}
