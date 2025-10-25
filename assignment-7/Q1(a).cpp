#include<iostream>
using namespace std;
int main(){
    int arr[5]={3,5,8,2,9};
    int n=5;
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
                int temp=arr[min];
                arr[min]=arr[i];
                arr[i]=temp;
            }
        }
        // if(min!=i){
        //     int temp=arr[min];
        //     arr[min]=arr[i];
        //     arr[i]=temp;
        // }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
