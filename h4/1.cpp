// Solution to https://www.acmicpc.net/problem/11974

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findmax(vector<int>& nums, int num) {
    // 100000 is bigger than N anyway
    int leftnum = 100000;
    int rightnum = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        int item = nums.at(i);
        if (item == num) {
            rightnum = i;
            if (leftnum == 100000) leftnum = i;
        }
    }

    // That's just the same spot...
    if (leftnum == rightnum) return 0;

    return rightnum - leftnum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int N;
    cin >> N;

    // Prefix sum
    vector<int> ids;
    int rolling = 0;

    // Prevents cases like 3 4 0 from not working correctly
    ids.push_back(0);

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        // Only mod 7 matters
        rolling = (rolling + num) % 7;
        ids.push_back(rolling);
    }

    int group = 0;
    for (int i = 0; i < 7; i++) group = max(group, findmax(ids, i));

    cout << group;

    return 0;
}