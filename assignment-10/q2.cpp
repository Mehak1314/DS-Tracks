#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    int arr[4] = {1, 2, 3, 4};
    int brr[4] = {3, 4, 5, 6};
    unordered_set<int> s;
    for (int i = 0; i < 4; i++)
    {
        s.insert(arr[i]);
    }
    cout << "COMMON ELEMENTS:" << endl;
    for (int i = 0; i < 4; i++)
    {
        if (s.count(brr[i]))
            cout << brr[i] << " ";
    }
}
