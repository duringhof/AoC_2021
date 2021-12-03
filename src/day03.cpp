#include "aoc_generic.hpp"

using namespace std;

vector<bool> string2bool(string s) {
    vector<bool> res;
    for (char c : s) {
        res.push_back(c == '1');
    }
    return res;
}

int boolvec2int(vector<bool> v) {
    int res = 0;
    for (int i = 0; i < v.size(); i++) {
        res += v[i] * pow(2, v.size() - i - 1);
    }
    return res;
}

vector<int> countOnes(vector<vector<bool>> v) {
    vector<int> res(v[0].size(), 0);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (v[i][j]) {
                res[j]++;
            }
        }
    }
    return res;
}

int main() {

    vector<string> lines = readLines("../input/input03.txt");
    vector<vector<bool>> input;
    for (string line : lines) {
        input.push_back(string2bool(line));
    }

    vector<int> counts = countOnes(input);

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

    vector<vector<bool>> OGR = input; // OGR stands for "Oxygen Generator Rating"
    vector<vector<bool>> CSR = input; // CSR stands for "CO2 Scrubber Rating"
    vector<vector<bool>> OGRnew = OGR;
    vector<vector<bool>> CSRnew = CSR;

    int pos = 0;
    int counter = 0;
    bool found = false;
    int target = 0;

    while (!found) {
        OGR = OGRnew;
        OGRnew.clear();
        counter = countOnes(OGR)[pos];
        target = (2*counter >= OGR.size());
        for (int i = 0; i < OGR.size(); i++) {
            if (OGR[i][pos] == target) {
                OGRnew.push_back(OGR[i]);
            }
        }
        found = (OGRnew.size() == 1);
        pos++;
    }
    OGR = OGRnew;

    pos = 0;
    found = false;
    target = 0;

    while (!found) {
        CSR = CSRnew;
        CSRnew.clear();
        counter = countOnes(CSR)[pos];
        target = (2*counter < CSR.size());
        for (int i = 0; i < CSR.size(); i++) {
            if ((CSR[i][pos] == target)) {
                CSRnew.push_back(CSR[i]);
            }
        }
        found = (CSRnew.size() == 1);
        pos++;
    }
    CSR = CSRnew;

    cout << "Part 2 - The life support rating of the submarine is "
        << boolvec2int(OGR[0]) << " multiplied by "
        << boolvec2int(CSR[0]) << " = "
        << boolvec2int(OGR[0])*boolvec2int(CSR[0]) << endl;
    
    return 0;
}