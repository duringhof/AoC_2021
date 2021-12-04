#include "aoc_generic.hpp"

using namespace std;

struct BingoNr {
    int value;
    bool drawn;
};

vector<vector<BingoNr>> lines2Card(vector<string> lines) {
    vector<vector<BingoNr>> card;
    for (int i = 0; i < 5; i++) {
        vector<BingoNr> row;
        stringstream ss(lines[i]);
        BingoNr n;
        for (int j = 0; j < 5; j++) {
            ss >> n.value;
            n.drawn = false;
            row.push_back(n);
        }
        card.push_back(row);
    }
    return card;
}

vector<int> line2nrs(string line) {
    vector<int> nrs;
    vector<string> nrs_str = split(line, ',');
    for (string nr_str : nrs_str) {
        nrs.push_back(stoi(nr_str));
    }
    return nrs;
}

bool checkRow(vector<vector<BingoNr>> card, int row) {
    for (int i = 0; i < 5; i++) {
        if (card[row][i].drawn == false) {
            return false;
        }
    }
    return true;
}

bool checkColumn(vector<vector<BingoNr>> card, int col) {
    for (int i = 0; i < 5; i++) {
        if (card[i][col].drawn == false) {
            return false;
        }
    }
    return true;
}

void printCard(vector<vector<BingoNr>> card) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << card[i][j].value << " ";
        }
        cout << endl;
    }
}

int sumOfUnmarked(vector<vector<BingoNr>> card) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (card[i][j].drawn == false) {
                sum += card[i][j].value;
            }
        }
    }
    return sum;
}

int main() {

    vector<string> lines = readLines("../input/input04.txt");

    vector<int> draws = line2nrs(lines[0]);

    int last_empty = 1;
    vector<string> lines_new;
    vector<vector<vector<BingoNr>>> cards;

    while (last_empty < lines.size()) {
        lines_new.clear();
        for (int i = 1; i < 6; i++) {
            lines_new.push_back(lines[last_empty + i]);
        }
        cards.push_back(lines2Card(lines_new));
        last_empty += 6;
    }

    int draw_nr = 0;
    bool firstbingo = false;
    bool lastbingo = false;

    vector<int> winning_cards;

    while (!lastbingo && draw_nr < draws.size()) {
        for (int card = 0; card < cards.size(); card++) {
            for (int row = 0; row < 5; row++) {
                for (int col = 0; col < 5; col++) {
                    if (cards[card][row][col].value == draws[draw_nr]) {
                        cards[card][row][col].drawn = true;
                        if (checkRow(cards[card], row) || checkColumn(cards[card], col)) {
                            if (!firstbingo) {
                                cout << "Part 1 - The score of the first winning board is: " 
                                     << cards[card][row][col].value * sumOfUnmarked(cards[card])
                                     << endl;
                                    firstbingo = true;
                            }
                            if (find(winning_cards.begin(), winning_cards.end(), card) == winning_cards.end()) {
                                winning_cards.push_back(card);
                            }
                            if (winning_cards.size() == cards.size() && !lastbingo) {
                                cout << "Part 2 - The score of the last winning board is: " 
                                     << cards[card][row][col].value * sumOfUnmarked(cards[card])
                                     << endl;
                                lastbingo = true;
                            }
                        }
                    }
                }
            }
        }
        draw_nr++;
    }

    return 0;
}