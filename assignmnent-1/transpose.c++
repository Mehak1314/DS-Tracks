#include<iostream>
using namespace std;
void input(int a[10][10],int row, int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>a[i][j];
        }
    }
}
void transpose(int a[10][10],int row, int col){
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            cout<<a[j][i]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int a[10][10],r,c;
    cout<<"Enter number of rows in matrix: ";
    cin>>r;
    cout<<"Enter number of coloumns in matrix: ";
    cin>>c;
    cout<<"Enter elements in matrix: \n";
    input(a,r,c);
    cout<<"\nTranspose of matrix is: \n";
    transpose(a,r,c);

}