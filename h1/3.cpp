#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

void printout(int arr[], int size) {
    sort(arr, arr + size);
    cout << "Largest: " << arr[size - 1] << "\n";
    cout << "Smallest: " << arr[0] << "\n";
    float average;
    if (size % 2 == 1) {
        average = arr[size / 2];
    } else {
        average = (float) (arr[size / 2] + arr[size / 2 - 1]) / 2;
    }
    cout << "Average: " << average << "\n";
}

int main() {
    string in;
    // Don't use << because it skips the \n
    // This makes getline think that it's the input
    getline(cin, in);

    int size = stoi(in);

    string n;
    getline(cin, n);
    
    int* nums = new int[size];

    istringstream iss (n);
    string num;
    int count = 0;
    while (getline(iss, num, ' ') && count < size) {
        nums[count++] = stoi(num);
    }

    printout(nums, size);

    return 0;
}