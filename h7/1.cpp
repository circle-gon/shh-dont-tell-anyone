#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Creates a binary partition
vector<int> partition(int num) {
    vector<int> partitions;

    int count = 1;
    while (num >= count) {
        partitions.push_back(count);
        num -= count;
        count *= 2;
    }
    if (num > 0) partitions.push_back(num);

    return partitions;
}

bool divisible(int items[6], int weight) {
    // Odd can never be divided
    if (weight % 2 == 1) return false;

    // Find a group of marbles that have a total weight of weight / 2
    // Use the multiple choice knapsack solution with each marble, with the
    // cost being the weight of the marble, with the maximum cost being weight / 2
    // Since the only way to increase the weight is to increase the cost 
    // (the relative value is the same), the solution will be the weight / 2
    // if it is possible, and lower if it is not
    int target = weight / 2;

    // Weight/value
    vector<int> sack;
    for (int i = 0; i < 6; i++) {
        vector<int> counts = partition(items[i]);

        // I am seriously going to die
        for (int count = 0; count < counts.size(); count++) {
            sack.push_back((i + 1) * counts.at(count));
        }
    }

    // Solve

    // Only store the next state and the current state
    // Each state relies on only its immediate predecessor, so all the previous
    // states can be discarded, saving a massive amount of memory
    int state[target + 1];
    int nextstate[target + 1];
    for (int i = 0; i <= sack.size(); i++) {
        for (int j = 0; j <= target; j++) {
            if (i > 0) {
                int prev = j - sack.at(i - 1);
                int left = prev >= 0 ? state[prev] + sack.at(i - 1) : 0;
                int right = state[j];

                int v = max(left, right);
                nextstate[j] = v;
            } else {
                nextstate[j] = 0;
            }
        }
        for (int j = 0; j <= target; j++) {
            state[j] = nextstate[j];
        }
    }

    int r = state[target];
    return r == target;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count = 1;

    while (true) {
        int items[6];
        int weight = 0;

        for (int i = 0; i < 6; i++) {
            int val;
            cin >> val;
            items[i] = val;
            weight += val * (i + 1);
        }

        if (weight == 0) break;

        bool divides = divisible(items, weight);
        if (count > 1) cout << "\n";
        cout << "Collection #" << count << ":\n";
        cout << (divides ? "Can" : "Can't");
        cout << " be divided.\n";

        count++;
    }

    return 0;
}