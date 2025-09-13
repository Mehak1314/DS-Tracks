#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter total elements: ";
    cin>>n;
    int arr[n];
    int element;
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                cout<<"Duplicate element found is: "<<arr[j];
                for (int k = j; k< n-1; k++) {
                    arr[k] = arr[k+1];
                }
                n--;
                j--;
            }
        }
    }
    
    cout<<"\nArray with unique elements: \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}