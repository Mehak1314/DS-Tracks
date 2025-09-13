#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;

    cout << "Enter first string: ";
    getline(cin, str1);
    cout << "Enter second string: ";
    getline(cin, str2);

    // Concatenate using + operator
    string result = str1 + " " + str2;

    // Concatenate str2 to str1
    // strcat(str1, " ");
    // strcat(str1, str2);
    // cout << "Concatenated String: " << str1 << endl;

    cout << "Concatenated String: " << result << endl;

    return 0;
}
