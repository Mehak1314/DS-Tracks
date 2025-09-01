#include<iostream>
#include<string>
using namespace std;    
int main()
{
    string str;
    cout<<"Enter total number of strings: ";
    int n;
    cin>>n;
    cin.ignore(); // To ignore the newline character after the integer input
    string arr[n];
    cout<<"Enter the strings:"<<endl;
    for(int i=0;i<n;i++)
    {
        getline(cin, arr[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                string temp=arr[i];
                arr[i]=arr[j];  
                arr[j]=temp;
            }
        }
    }
    cout<<"Strings in sorted order:"<<endl;     
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}