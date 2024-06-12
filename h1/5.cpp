#include <iostream>

using namespace std;

int main() {
    int num = 5;
    int* pointer = &num;

    cout << num << "\n";

    *pointer = 2;
    cout << num << "\n";
}