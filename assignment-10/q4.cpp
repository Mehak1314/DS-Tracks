#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int, int> m;
    int arr[6] = {4, 5, 1, 2, 0, 4};
    for (int i = 0; i < 6; i++)
        m[arr[i]]++;
    bool found = false;
    for (int i = 0; i < 6; i++)
    {
        if (m[arr[i]] == 1)
        {
            cout << arr[i] << " IS THE FIRST NON-REPEATING ELEMENT.\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "NO NON-REPEATING ELEMENT.\n";
    return 0;
}
