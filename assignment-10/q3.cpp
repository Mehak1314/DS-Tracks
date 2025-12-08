#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<int, int> m;
    int arr[6] = {2, 3, 2, 4, 3, 2};
    for (int i = 0; i < 6; i++)
    {
        {
            m[arr[i]]++;
        }
    }
    for (auto i : m)
    {
        cout << i.first << "->" << i.second << endl;
    }
}
