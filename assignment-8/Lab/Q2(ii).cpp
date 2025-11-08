//non recursive binary search tree
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
    node* current = root;
    while (current != NULL) {
        if (current->data == key) {
            cout << "Key " << key << " found in the tree!" << endl;
            return;
        } else if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }
    cout << "Key " << key << " not found!" << endl;
}
int main(){
    node* root=NULL;
    int key;
    root=createtree(root);
    cout<<"\nEnter key to search: ";
    cin>>key;
    search(root,key);
}
