#include "aoc_generic.hpp"

using namespace std;

vector<int> adjacents(vector<vector<int>> &map, int x, int y) {
    vector<int> adj;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            if (x + i < 0 || x + i >= map[0].size()) continue;
            if (y + j < 0 || y + j >= map.size()) continue;
            if (i == j) continue;
            adj.push_back(map[y+j][x+i]);
        }
    }
    return adj;
}

bool isLow(vector<vector<int>> &map, int x, int y) {
     for (auto &adj : adjacents(map, x, y)) {
        if (adj <= map[y][x]) return false;
     }
     return true;
}

int calcRisk(vector<int> &lows) {
    int risk = 0;
    for (auto &low : lows) {
        risk += low+1;
    }
    return risk;
}

int main() {

     vector<string> lines = readLines("../input/input09.txt");

     vector<vector<int>> map;
     for (auto line : lines) {
          vector<int> row;
          for (char c : line) {
               row.push_back(c-'0');
          }
          map.push_back(row);
     }

     vector<int> lows;
     for (int i = 0; i < map[0].size(); i++) {
          for (int j = 0; j < map.size(); j++) {
               if (isLow(map, i, j)) lows.push_back(map[j][i]);
          }
     }

     cout << "Part 1 - The total risk level of identified lows is "
          << calcRisk(lows)
          << endl;

     cout << "Part 2 - Not ready yet... "
          //<< answer 
          << endl;

    return 0;
}