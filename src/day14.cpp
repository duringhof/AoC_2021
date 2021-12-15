#include "aoc_generic.hpp"
#include <map>

using namespace std;

void executeReactions(vector<vector<string>>& reactions, vector<long>& reactionCounts) {
    vector<long> newReactionCounts(reactionCounts.size(), 0);
    for (int i = 0; i < reactions.size(); i++) {
        if (reactionCounts[i] > 0) {
            for (int j = 0; j < reactions.size(); j++) {
                if (reactions[j][0] == reactions[i][1] || reactions[j][0] == reactions[i][2]) {
                    newReactionCounts[j] += reactionCounts[i];
                }
            }
        }
    }
    reactionCounts = newReactionCounts;
}

int countChars(string& s, char c) {
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            count++;
        }
    }
    return count;
}

map<char,long> countElements(vector<vector<string>>& reactions, vector<long>& reactionCounts, string& polymerTemplate) {
    map<char, long> elements;
    for (int i = 0; i < reactions.size(); i++) {
        elements[reactions[i][0][0]] += reactionCounts[i];
    }
    elements[polymerTemplate[polymerTemplate.size()-1]] += 1;
    return elements;
}

long findMostCommon(map<char, long> elements) {
    long mostCommon = 0;
    for (auto& element : elements) {
        if (element.second > mostCommon) {
            mostCommon = element.second;
        }
    }
    return mostCommon;
}

long findLeastCommon(map<char, long> elements) {
    long leastCommon = LONG_MAX;
    for (auto& element : elements) {
        if (element.second < leastCommon) {
            leastCommon = element.second;
        }
    }
    return leastCommon;
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
        string newPair1, newPair2;
        newPair1.append(1, input[0]);
        newPair1.append(1, newPolymer[0]);
        newPair2.append(1, newPolymer[0]);
        newPair2.append(1, input[1]);
        reactions.push_back({input, newPair1, newPair2});
    }

    vector<long> reactionCounts(reactions.size(), 0);

    for (int i = 0; i < polymerTemplate.size()-1; i++) {
        string pair;
        pair.append(1, polymerTemplate[i]);
        pair.append(1, polymerTemplate[i+1]);
        for (auto j = 0; j < reactions.size(); j++) {
            if (pair == reactions[j][0]) {
                reactionCounts[j]++;
            }
        }
    }

    for (int itr = 0; itr < 10; itr++) {
        executeReactions(reactions, reactionCounts);
    }

    cout << "Part 1 - After 10 iterations, the answer is "
         << findMostCommon(countElements(reactions, reactionCounts, polymerTemplate)) - 
            findLeastCommon(countElements(reactions, reactionCounts, polymerTemplate))
         << endl;

    for (int itr = 0; itr < 30; itr++) {
        executeReactions(reactions, reactionCounts);
    }

    cout << "Part 1 - After 40 iterations, the answer is "
         << findMostCommon(countElements(reactions, reactionCounts, polymerTemplate)) - 
            findLeastCommon(countElements(reactions, reactionCounts, polymerTemplate))
         << endl;

    return 0;
}