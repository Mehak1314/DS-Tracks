#include <iostream>
#include <vector>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    int count0 = 0, count1 = 0;

    for (int s : students) {
        if (s == 0) count0++;
        else count1++;
    }

    for (int sw : sandwiches) {
        if (sw == 0) {
            if (count0 == 0) return count1; // no student wants 0
            count0--;
        } else {
            if (count1 == 0) return count0; // no student wants 1
            count1--;
        }
    }

    return 0;
}

int main() {
    vector<int> students = {1,1,0,0};
    vector<int> sandwiches = {0,1,0,1};

    cout << "Number of students who cannot eat: "
         << countStudents(students, sandwiches) << endl;
    return 0;
}
