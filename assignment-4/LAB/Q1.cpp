#include<iostream>
using namespace std;
class Queue{
    int arr[10];
    int front,rear;
    public:
    Queue(){
        front=-1;
        rear=-1;
    }
    void isFull(){
        if(rear==9){
            cout<<"Queue is full"<<endl;
        }
        else{
            cout<<"Queue is not full"<<endl;
        }
    }
    void isEmpty(){
        if(front==-1){
            cout<<"Queue is empty"<<endl;
        }
        else{
            cout<<"Queue is not empty"<<endl;
        }
    }
    void enqueue(int x){
         if (rear == 9) {
            cout << "Queue is full. Cannot enqueue " << x << endl;
            return;
        }
        else if(front==-1){
            front=0;
        }
        arr[++rear]=x;
        cout<<x<<" is added"<<endl;
    }
    void dequeue(){
        if(front==-1){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        cout<<arr[front]<<" deleted from Queue."<<endl;
        if(front==rear){
            front=rear=-1;
        }
        else{
            front++;
        }
    }
    void peek(){
        if(front==-1){
            cout<<"Queue is empty"<<endl;
        }
        else{
            cout<<arr[front]<<" is your Peek element"<<endl;
        }
    }
    void display(){
        if (front == -1) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    Queue q;
    cout<<"\nQUEUE MENU"<<endl;
    int choice,val;
    do{
    cout<<"Enter operation you want to perform: \n1.IsFull\n2.IsEmpty\n3.Enqueue\n4.Dequeue\n5.Peek\n6.Display Queue\n\nEnter: ";
    cin>>choice;
    switch(choice){
        case 1:
        cout<<"Check if Queue is Full: "<<endl;
        q.isFull();
        break;
        case 2:
        cout<<"Check if Queue is empty: "<<endl;
        q.isEmpty();
        break;
        case 3:
        cout<<"Enter element to add in queue: ";
        cin>>val;
        q.enqueue(val);
        break;
        case 4:
        q.dequeue();
        break;
        case 5:
        q.peek();
        break;
        case 6:
        q.display();
        break;
        default:
        cout << "Invalid choice! Try again." << endl;
    }
    }
    while(choice!=0);
} 