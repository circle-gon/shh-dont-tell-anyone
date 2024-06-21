#include <algorithm>
#include <iostream>

using namespace std;

void printarr(int arr[], int n) {
    cout << "array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

// algorithm:
// use aux space u = min(s, n - s) to do partial join of both sorted arrays
// then push the remaning parts of of the first sorted to tbe second sorted
// move aux space to the front of the array, and repeat until sorted
// Has an upper bound on time of 2n + s*ceil(n/u), which is O(n) if s <= 1/2n (or u = s)
// If s > 1/2n, it is no longer O(n), but this problem can be solved by swapping the first
// and second sorted areas in place (to not use more memory)
// 2n because each number must be pushed to the aux, then pushed back to the original array
// s*ceil(n/u) because at most the first s numbers must be pushed forward each time
// (not sure how to improve time bound, maybe n-s instead of n but it might be possible for the
// time bound to be higher)

void mergesort(int arr[], int s, int n) {
    int size = min(s, n - s);
    int* aux = new int[size];

    int p1 = 0, p2 = s, auxidx = 0, startidx = 0, rightsort = 0, prevright = 0;

    // not sorted?
    while (p1 < (s + prevright) || p2 < n) {
        // 1. partial join
        while ((p1 < (s + prevright) || p2 < n) && auxidx < size) {
            // is not exhausted, and second is exhausted
            if (p1 < (s + prevright) && (p2 >= n || arr[p1] <= arr[p2])) {
                aux[auxidx] = arr[p1];
                p1++;
            } else {
                aux[auxidx] = arr[p2];
                p2++;
                rightsort++;
            }
            auxidx++;
        }

        // 2. push first sort to right
        // p2 is the start of the next sorted area
        // p1 is the first sorted area start
        // (s + prevright) is this sorted area's end
        int diff = s + prevright - p1;
        for (int i = diff - 1; i >= 0; i--) arr[p2 - diff + i] = arr[p1 + i];
        p1 = p2 - diff;

        // 3. push aux back to arr
        for (int i = 0; i < auxidx; i++) arr[startidx + i] = aux[i];

        // 4. reset
        startidx += auxidx;
        prevright = rightsort;
        auxidx = 0;
    }
}

int main() {
    int arr[] = {2, 5, 10, 13, -1, 5, 7, 9};

    mergesort(arr, 4, 8);

    for (auto i: arr) {
        cout << i << " ";
    }

    cout << "\n";

    return 0;
}