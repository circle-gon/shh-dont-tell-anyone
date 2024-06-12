#include <iostream>

using namespace std;

int main() {
    int num = 5;
    // Note to self: you can't initialize the pointer's slot with a default value
    // Need to create a dummy variable in order to get a location
    int* pointer = &num;

    cout << num << "\n";

    *pointer = 2;
    cout << num << "\n";
}