#include<iostream>
using namespace std;
void mat_input(int mat[10][10], int row, int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>mat[i][j];
        }
    }
}
void mul(int a[10][10], int b[10][10],int c[10][10],int r1, int c1,int r2,int c2){
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            c[i][j]=0;
            for(int k=0;k<c1;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
}
void display(int c[10][10],int row, int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int a[10][10];
    int b[10][10];
    int c[10][10];
    int r1,r2,c1,c2;
    cout<<"Enter Matrix 1 rows: ";
    cin>>r1;
    cout<<"Enter Matrix 1 coloumn: ";
    cin>>c1;
    cout<<"Enter elemnets in matrix 1: \n";
    mat_input(a,r1,c1);
    cout<<"Enter Matrix 2 rows: ";
    cin>>r2;
    cout<<"Enter Matrix 2 coloumn: ";
    cin>>c2;
    cout<<"Enter elemnets in matrix 2: \n";
    mat_input(b,r2,c2);
    if(c1!=r2){
        cout<<"Invalid matrix!!\n";
        return 0;
    }
    cout<<"\nThe product of matrix is: "<<endl;
    mul(a,b,c,r1,c1,r2,c2);
    display(c,r1,c2);
 

}
