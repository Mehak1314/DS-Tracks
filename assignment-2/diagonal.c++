#include<iostream>
using namespace std;
void diagonal(int dia[], int n){
    cout<<"The diagonal elements are:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                cout<<dia[i]<<" ";
            }
            else{
                cout<<"0 ";
            }
    }
    cout<<endl;
}
}
int main(){
    int n;
    cout<<"Enter the size of the square matrix: ";
    cin>>n;
    int dia[n];
    cout<<"Enter the elements of the matrix:"<<endl;
    for(int i=0;i<n;i++){
        cin>>dia[i];
    }
    diagonal(dia, n);
    return 0;
}