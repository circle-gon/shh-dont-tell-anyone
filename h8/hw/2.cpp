#include <iostream>
#include <string>
#include <vector>

using namespace std;

void add(bool gates[2001][2001], int x, int y) {
    gates[x + 1000][y + 1000] = true;
}

void flood(bool gates[2001][2001], bool visited[2001][2001], int i, int j) {
    vector<pair<int, int>> spots;
    
    spots.push_back(pair<int, int>(i, j));

    // Using recursion apparently causes segmentation faults
    // I have no idea why but I could really care less
    while (spots.size() > 0) {
        pair<int, int> spot = spots.back();
        spots.pop_back();

        int x = spot.first, y = spot.second;

        if (
            x < 0 || 
            x > 2000 || 
            y < 0 || 
            y > 2000
        ) continue;
        if (
            gates[x][y] ||
            visited[x][y]
        ) continue;

        visited[x][y] = true;
        spots.push_back(pair<int, int>(x + 1, y));
        spots.push_back(pair<int, int>(x - 1, y));
        spots.push_back(pair<int, int>(x, y + 1));
        spots.push_back(pair<int, int>(x, y - 1));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);

    int N;
    cin >> N;

    string instruction;
    cin >> instruction;

    bool gates[2001][2001];
    bool visited[2001][2001];

    int curX = 0, curY = 0;

    add(gates, 0, 0);

    // NEVER forget to initialize your variables
    // otherwise bad things happen
    for (int i = 0; i <= 2000; i++) {
        for (int j = 0; j <= 2000; j++) {
            gates[i][j] = false;
            visited[i][j] = false;
        }
    }

    for (char& inst: instruction) {
        string s(1, inst);

        if (s == "N") {
            add(gates, curX, curY + 1);
            add(gates, curX, curY + 2);
            curY += 2;
        } else if (s == "S") {
            add(gates, curX, curY - 1);
            add(gates, curX, curY - 2);
            curY -= 2;
        } else if (s == "E") {
            add(gates, curX + 1, curY);
            add(gates, curX + 2, curY);
            curX += 2;
        } else if (s == "W") {
            add(gates, curX - 1, curY);
            add(gates, curX - 2, curY);
            curX -= 2;
        }
    }

    int need = -1;

    for (int i = 0; i <= 2000; i++) {
        for (int j = 0; j <= 2000; j++) {
            if (!visited[i][j] && !gates[i][j]) {
                flood(gates, visited, i, j);
                need++;
            }
        }
    }

    cout << need;

    return 0;
}