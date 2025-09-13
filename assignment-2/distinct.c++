#include<iostream>
using namespace std;
void distint(int arr[],int n){
    int count=0;
    for(int i=0;i<n;i++){
        bool distint=true;
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                distint=false;
                break;
            }
        }
        if(distint){
            count++;
        }
    }
    cout<<"Total distint: "<<count<<endl;
}
int main(){
    int arr[5]={1,2,3,2,4};
    distint(arr,5);
}