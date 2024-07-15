#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n, q;
        cin >> n >> q;

        int candies[n];

        for (int j = 0; j < n; j++) {
            cin >> candies[j];
        }

        sort(candies, candies + n, greater<>());

        vector<int> sums;
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += candies[j];
            sums.push_back(sum);
        }

        for (int j = 0; j < q; j++) {
            int query;
            cin >> query;
            
            int idx = lower_bound(sums.begin(), sums.end(), query) - sums.begin();
            
            if (idx == n) cout << "-1";
            else cout << idx + 1;

            cout << "\n";
        }
    }

    return 0;
}