#include <set>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<int> out;
    int factors[] = {1, 2, 3, 5, 7};
    int now = 0;

    out.insert(1);

    while (out.size() < 5842) {
        // Smallest number greater than the previous humble number
        int high = *out.upper_bound(now);
        now = high;

        for (int i = 0; i < 5; i++) {
            // 2 billion * 7 > max int value
            long long curr = (long long) high * factors[i];
            if (curr <= 2e9) out.insert(curr);
        }
    }

    int* nums = new int[5842];
    int j = 0;
    for (set<int>::iterator it = out.begin(); it != out.end();) {
        nums[j] = *it;
        it++;
        j++;
    }

    string suffixes[] = {"th", "st", "nd", "rd", "th"};

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        
        int num = nums[n - 1];
        int m = n % 100;
        string suffix = m >= 11 && m <= 13 ? suffixes[0] : suffixes[min(n % 10, 4)];
        cout << "The " << n << suffix << " humble number is " << num << ".\n";
    }
}