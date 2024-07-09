#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    
    int prices[n];
    long long sums[n + 1];
    for (int i = 0; i < n; i++) cin >> prices[i];

    sort(prices, prices + n, greater<>());

    long long running = 0;
    sums[0] = running;
    for (int i = 0; i < n; i++) {
        running += prices[i];
        sums[i + 1] = running;
    }

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        cout << sums[x] - sums[x - y] << "\n";
    }

    return 0;
}