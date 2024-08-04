#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int M;

    cin >> N >> M;

    bool lights[N];

    for (int i = 0; i < N; i++) lights[i] = false;

    for (int i = 0; i < M; i++) {
        int op, si, ei;
        cin >> op >> si >> ei;

        if (op == 0) {
            for (int j = si; j <= ei; j++) {
                lights[j - 1] = !lights[j - 1];
            }
        } else {
            int count = 0;
            for (int j = si; j <= ei; j++) {
                if (lights[j - 1]) count++;
            }
            cout << count << "\n";
        }
    }

    return 0;
}