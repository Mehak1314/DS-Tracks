//Recursive Binary search
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
void search(node* root,int key){
    if(root==NULL){
        cout<<"Empty or not found!!"<<endl;
    }
    if(root->data==key){
        cout<<"Root key found!!"<<endl;
    }
    else if(root->data<key){
        search(root->right,key);
    }
    else{
        search(root->left,key);
    }

}
int main(){
    node* root=NULL;
    int key;
    root=createtree(root);
    cout<<"\nEnter key to search: ";
    cin>>key;
    search(root,key);
}
