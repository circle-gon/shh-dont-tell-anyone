#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int N;
    cin >> N;

    int P[N];
    int H[N];
    int S[N];

    int pcount = 0, hcount = 0, scount = 0;

    string input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        if (input == "P") pcount++;
        if (input == "H") hcount++;
        if (input == "S") scount++;

        P[i] = pcount;
        H[i] = hcount;
        S[i] = scount;
    }

    int m = 0;
    for (int i = 0; i < N; i++) {
        int max1 = max(max(P[i], H[i]), S[i]);
        int max2 = max(max(P[N - 1] - P[i], H[N - 1] - H[i]), S[N - 1] - S[i]);
        m = max(m, max1 + max2);
    }

    cout << m;

    return 0;
}