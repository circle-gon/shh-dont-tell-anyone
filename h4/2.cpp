// Solution to https://www.acmicpc.net/problem/15761

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);

    int N;
    cin >> N;

    vector<int> nums;
    for (int i = 0; i < N; i++) {
        int j;
        cin >> j;
        nums.push_back(j);
    }

    // Bigger goes first
    sort(nums.begin(), nums.end(), greater<>());

    int small = N;
    for (int i = 0; i < N; i++) {
        if (nums.at(i) < i) {
            small = i;
            break;
        }
    }

    cout << small;
    return 0;
}