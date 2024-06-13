#include <algorithm>
#include <iostream>

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
    int size;
    cin >> size;
    
    int* nums = new int[size];

    int count = 0;
    while (count < size) {
        cin >> nums[count++];
    }

    printout(nums, size);

    return 0;
}