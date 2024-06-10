#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream input;
    ofstream output;
    input.open("input.txt");
    output.open("output.txt");

    string a = "";
    bool should = false;
    int lines = 0;
    int words = 0;
    int chars = 0;

    while (getline(input, a)) {
        if (should) output << "\n";
        should = true;

        output << a;
        lines++;
        words++;
        for (char l: a) {
            if (string({l}) == " ") {
                words++;
            } else {
                chars++;
            }
        }
    }

    cout << "Lines: " << lines << "\n";
    cout << "Words: " << words << "\n";
    cout << "Non-whitespace characters: " << chars << "\n";

    return 0;
}