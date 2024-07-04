#include <iostream>
#include <math.h>

using namespace std;

void moverange(int arr[], int a, int b, int r) {
    for (int i = 0; i <= r; i++) {
        int j = arr[a + i];
        arr[a + i] = arr[b + i];
        arr[b + i] = j;
    }
}

void mergesort(int arr[], int s, int n) {
    int r = sqrt(n);

    // do the insertion sort
    int i = 1;
    while (i < r) {
        
    }
}

int main() {
    return 0;
}