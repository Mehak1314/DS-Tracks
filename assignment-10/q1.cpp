#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    int flag = 0;
    unordered_set<int> s;
    int arr[4] = {1, 2, 3, 1};
    for (int i = 0; i < 4; i++)
    {
        if (s.count(arr[i]))
            flag = 1;
        else
        {
            s.insert(arr[i]);
        }
    }
    if (flag == 1)
        cout << "DUPLICATES EXIST";
    else
        cout << "NO DUPLICATES FOUND";
}
