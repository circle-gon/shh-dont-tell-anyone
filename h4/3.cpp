#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Gallon {
    int price;
    int max;
    Gallon() {};
};

istream& operator>>(istream& is, Gallon& gallon) {
    is >> gallon.max;
    is >> gallon.price;
    return is;
}

bool compare(Gallon& a, Gallon& b) {
    if (a.price != b.price) return a.price > b.price;
    return a.max > b.max;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);

    int N;
    int M;
    int R;
    cin >> N >> M >> R;

    vector<int> c;
    vector<Gallon> p;
    vector<int> r;

    for (int i = 0; i < N; i++) {
        int j;
        cin >> j;
        c.push_back(j);
    }
    for (int i = 0; i < M; i++) {
        Gallon g;
        cin >> g;
        p.push_back(g);
    }
    for (int i = 0; i < R; i++) {
        int j;
        cin >> j;
        r.push_back(j);
    }
    sort(c.begin(), c.end());
    sort(p.begin(), p.end(), compare);
    sort(r.begin(), r.end(), greater<>());

    int lowidx = 0, highidx = N - 1, milkidx = 0, sellidx = 0;
    long long profits = 0;

    while (lowidx <= highidx) {
        // Profits from selling the weak cow (lowidx)
        int sellprofit = sellidx < R ? r.at(sellidx) : 0;

        // Profits from milking the strong cow (highidx)
        long long milkprofit = 0;
        int milkprod = c.at(highidx);
        int newidx = milkidx;
        int remaining = 0;
        while (milkprod > 0 && newidx < M) {
            Gallon curr = p.at(newidx);
            int total = min(milkprod, curr.max);
            milkprod -= total;
            milkprofit += total * curr.price;
            if (milkprod > 0) newidx++;
            else remaining = curr.max - total;
        }

        if (sellprofit >= milkprofit) {
            // You should sell the cow
            lowidx++;
            sellidx++;
            profits += sellprofit;
        } else {
            // You should milk the cow
            highidx--;
            milkidx = newidx;
            if (milkidx < M) p.at(milkidx).max = remaining;
            profits += milkprofit;
        }
    }

    cout << profits;
}