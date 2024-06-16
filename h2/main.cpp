#include <iostream>
#include <algorithm>

using namespace std;

struct Laptop {
    int price;
    int quality;
};

bool laptopsort(Laptop a, Laptop b) {
    if (a.price < b.price) return true;
    // Want high quality ahead so it checks correctly
    if (a.price == b.price && a.quality < b.quality) return true;
    return false;
}

int main() {
    int n;
    cin >> n;

    Laptop* laptops = new Laptop[n];

    for (int i = 0; i < n; i++) {
        int p;
        int q;
        cin >> p >> q;
        laptops[i].price = p;
        laptops[i].quality = q;
    }

    sort(laptops, laptops + n, laptopsort);

    /*for (int i = 0; i < n; i++) {
        Laptop l = laptops[i];
        cout << "Price: " << l.price << "\n";
        cout << "Quality: " << l.quality << "\n";
    }*/

    bool correct = false;
    for (int i = 0; i < n - 1; i++) {
        Laptop a = laptops[i];
        Laptop b = laptops[i + 1];
        if (a.price < b.price && a.quality > b.quality) {
            correct = true;
            break;
        }
    }

    if (correct) cout << "Happy Alex";
    else cout << "Poor Alex";

    return 0;
}