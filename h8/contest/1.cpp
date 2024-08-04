#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int K;

    cin >> N;
    cin >> K;

    int trees[N];

    for (int i = 0; i < N; i++) {
        cin >> trees[i];
    }

    sort(trees, trees + N, greater<>());

    return 0;
}