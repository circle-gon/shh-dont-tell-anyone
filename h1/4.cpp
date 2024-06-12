#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

int main() {
    vector<int> nums;

    for (int i = 1; i <= 10; i++) nums.push_back(i);

    vector<int>::iterator it = nums.begin();
    while (it != nums.end()) {
        int item = *it;
        if (item % 2 == 0) it = nums.erase(it);
        else it++;
    }

    bool add = false;
    for (auto num: nums) {
        if (add) cout << " ";
        add = true;
        cout << num;
    }
    cout << "\n";
    
    return 0;
}