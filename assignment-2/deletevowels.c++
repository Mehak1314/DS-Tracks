#include<iostream>
#include<string>    
using namespace std;
int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    string result;
    for (char c : str) {
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            result += c;
        }
    }
    cout << "String after removing vowels: " << result << endl;
    return 0;
}