#include <iostream>
using namespace std;

void displayMenu() {
    cout << "\n--- ARRAY MENU OPERATIONS ---\n";
    cout << "1. CREATE\n";
    cout << "2. DISPLAY\n";
    cout << "3. INSERT\n";
    cout << "4. DELETE\n";
    cout << "5. LINEAR SEARCH\n";
    cout << "6. EXIT\n";
    cout << "-----------------------------\n";
}

int main() {
    int arr[30], n = 0, choice, element, index;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: // CREATE
                cout << "Enter number of elements: ";
                cin >> n;
                if (n > 30) {
                    cout << "Max size is 30!\n";
                    n = 30;
                }
                cout << "Enter " << n << " elements:\n";
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                }
                break;
                
            case 2: // DISPLAY
                if (n == 0) {
                    cout << "Array is empty!\n";
                } else {
                    cout << "Array elements: ";
                    for (int i = 0; i < n; i++) {
                        cout << arr[i] << " ";
                    }
                    cout << endl;
                }
                break;
                
            case 3: // INSERT
                if (n >= 30) {
                    cout << "Array is full!\n";
                } else {
                    cout << "Enter position (0 to " << n << "): ";
                    cin >> index;
                    if (index < 0 || index > n) {
                        cout << "Invalid position!\n";
                    } else {
                        cout << "Enter element to insert: ";
                        cin >> element;
                        for (int i = n; i > index; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[index] = element;
                        n++;
                    }
                }
                break;
                
            case 4: // DELETE
                if (n == 0) {
                    cout << "Array is empty!"<<endl;
                } else {
                    cout << "Enter index to delete (0 to " << n - 1 << "): ";
                    cin >> index;
                    if (index < 0 || index >= n) {
                        cout << "Invalid index!\n";
                    } else {
                        for (int i = index; i < n - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        n--;
                        cout << "Element deleted successfully.\n";
                    }
                }
                break;
                
            case 5: // LINEAR SEARCH
                if (n == 0) {
                    cout << "Array is empty!\n";
                } else {
                    cout << "Enter element to search: ";
                    cin >> element;
                    bool found = false;
                    for (int i = 0; i < n; i++) {
                        if (arr[i] == element) {
                            cout << "Element found at index " << i << endl;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Element not found!\n";
                    }
                }
                break;
                
            case 6: // EXIT
                cout << "Exiting...\n";
                break;
                
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);
    
    return 0;
}
