#include "aoc_generic.hpp"

using namespace std;

vector<bool> string2bool(string s) {
    vector<bool> res;
    for (char c : s) {
        res.push_back(c == '1');
    }
    return res;
}

int main() {

    vector<string> lines = readLines("../input/input03.txt");
    vector<vector<bool>> input;
    for (string line : lines) {
        input.push_back(string2bool(line));
    }

    vector<int> counts(input[0].size(), 0);

    
    for (auto code : input) {
        for (int i = 0; i < code.size(); i++) {
            if (code[i]) {
                counts[i]++;
            }
        }
    }

    int epsilon = 0;
    int gamma = 0;
    for (int j = 0; j < counts.size(); j++) {
        if (counts[j] > input.size()/2) {
            gamma += pow(2, counts.size()-j-1);
        } else {
            epsilon += pow(2, counts.size()-j-1);
        }
    }
    
    cout << "Part 1 - The power of the submarine is " << gamma*epsilon << endl;
    cout << "Part 2 - Day 3 is not ready yet... " << endl;
    
    return 0;
}