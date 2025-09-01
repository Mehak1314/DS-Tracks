#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;

    // Check if the character is uppercase
    if (ch >= 'A' && ch <= 'Z') {
        char lower = ch + 32;  // ASCII conversion
        cout << "Lowercase character: " << lower << endl;
    } else {
        cout << "The entered character is not uppercase!" << endl;
    }

    return 0;
}




// #include <iostream>
// #include <string>
// #include <cctype>  // for tolower()
// using namespace std;

// int main() {
//     string str;
//     cout << "Enter a string in uppercase: ";
//     getline(cin, str);

//     // Convert each character
//     for (int i = 0; i < str.length(); i++) {
//         str[i] = tolower(str[i]);  
//     }

//     cout << "Lowercase string: " << str << endl;
//     return 0;
// }
