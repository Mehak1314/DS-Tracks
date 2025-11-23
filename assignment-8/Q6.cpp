#include<iostream>
using namespace std;
class heap {
public:
    int arr[100];
    int size;
    heap() {
        arr[0] = -1;
        size = 0;
    }
    void heapify(int arr[], int n, int i){
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;
        if(left <= n && arr[left] > arr[largest]) largest = left;
        if(right <= n && arr[right] > arr[largest]) largest = right;
        if(largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }
    void insert(int num) {
        size++;
        int ind = size;
        arr[ind] = num;
        while(ind > 1) {
            int parent = ind / 2;
            if(arr[parent] < arr[ind]) {
                swap(arr[parent], arr[ind]);
                ind = parent;
            } 
            else break;
        }
    }
    int getmax() {
        if(size == 0) {
            cout << "Priority Queue empty\n";
            return -1;
        }
        return arr[1];
    }
    int extractmax() {
        if(size == 0) {
            cout << "Priority Queue empty\n";
            return -1;
        }
        int maxnum = arr[1];
        arr[1] = arr[size];
        size--;
        heapify(arr, size, 1);
        return maxnum;
    }
    void display() {
        for(int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    heap h;
    int choice, num;
    while(true) {
        cout << "\n1. Insert\n2. Get Maximum\n3. Extract Maximum\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if(choice == 1) {
            cout << "Enter num: ";
            cin >> num;
            h.insert(num);
        }
        else if(choice == 2) {
            cout << "Max element: " << h.getmax() << endl;
        }
        else if(choice == 3) {
            cout << "Extracted Max: " << h.extractmax() << endl;
        }
        else if(choice == 4) {
            h.display();
        }
        else break;
    }
    return 0;
}
