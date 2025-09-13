#include<iostream>
using namespace std;
void input(int a[10][10],int row, int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>a[i][j];
        }
    }
}
void row_sum(int a[10][10],int row,int col){
    int sum;
    for(int i=0;i<row;i++){
        sum=0;
        for(int j=0;j<col;j++){
            sum+=a[i][j];
        }
        cout<<"Row "<<i+1<<" sum is: "<<sum<<endl;
    }
    
}
void col_sum(int a[10][10], int row, int col) {
    for (int j = 0; j < col; j++) {
        int sum = 0;
        for (int i = 0; i < row; i++) {
            sum += a[i][j];
        }
        cout<<"Col "<<j+1<<" sum is: "<<sum<<endl; 
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
    cout<<"Your matrix is: "<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\nSum of each row is: \n"<<endl;
    row_sum(a,r,c);
    cout<<"\nSum of each coloum is: \n"<<endl;
    col_sum(a,r,c);
}