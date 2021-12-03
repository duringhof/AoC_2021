#include "aoc_generic.hpp"

using namespace std;

int main() {

    vector<string> codes = readLines("../input/input03.txt");

    vector<int> counts(codes[0].size(), 0);

    
    for (auto code : codes) {
        for (int i = 0; i < codes[0].size(); i++) {
            if (code[i] == '1') {
                counts[i]++;
            }
        }
    }

    int epsilon = 0;
    int gamma = 0;
    for (int j = 0; j < counts.size(); j++) {
        if (counts[j] > codes.size()/2) {
            epsilon += pow(2, counts.size()-j-1);
        } else {
            gamma += pow(2, counts.size()-j-1);
        }
    }
    
    cout << "Part 1 - The power of the submarine is " << gamma*epsilon << endl;
    cout << "Part 2 - Day 3 is not ready yet... " << endl;
    
    return 0;
}