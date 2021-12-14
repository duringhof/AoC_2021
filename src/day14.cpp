#include "aoc_generic.hpp"
#include <map>

using namespace std;

string executeReaction(char first, char second, vector<vector<string>>& reactions) {
    string result(1,first);
    for (auto& reaction : reactions) {
        if (reaction[0][0] == first && reaction[0][1] == second) {
            result.append(1, reaction[1][0]);
        }
    }
    //result.append(1, second);
    return result;
}

string polymerConversion(vector<vector<string>>& reactions, string polymerInput) {
    string polymerOutput;
    for (int c = 0; c < polymerInput.size()-1; c++) {
        char first = polymerInput[c];
        char next = polymerInput[c+1];
        polymerOutput += executeReaction(first, next, reactions);
    }
    polymerOutput += polymerInput[polymerInput.size()-1];
    return polymerOutput;
}

int mostCommon(string input) {
    map<char, int> charCount;
    for (char c : input) {
        charCount[c]++;
    }
    int maxCount = 0;
    char maxChar = ' ';
    for (auto& c : charCount) {
        if (c.second > maxCount) {
            maxCount = c.second;
            maxChar = c.first;
        }
    }
    return maxCount;
}

int leastCommon(string input) {
    map<char, int> charCount;
    for (char c : input) {
        charCount[c]++;
    }
    int minCount = INT_MAX;
    char minChar = ' ';
    for (auto& c : charCount) {
        if (c.second < minCount) {
            minCount = c.second;
            minChar = c.first;
        }
    }
    return minCount;
}
 
int main() {

    vector<string> lines = readLines("../input/input14.txt");

    string polymerTemplate = lines[0];

    vector<vector<string>> reactions;

    for (int i=2; i < lines.size(); i++) {
        stringstream ss(lines[i]);
        string input, dummy, newPolymer;
        ss >> input;
        ss >> dummy;
        ss >> newPolymer;
        reactions.push_back({input, newPolymer});
    }

    string polymer = polymerTemplate;

    for (int i=0; i < 10; i++) {
        polymer = polymerConversion(reactions, polymer);
    }

    cout << "Part 1 - After 10 iterations, the answer is "
         << mostCommon(polymer) - leastCommon(polymer)
         << endl;

    cout << "Part 2 - Not done..."
         << endl;

    return 0;
}