#include "aoc_generic.hpp"

using namespace std;

struct Fish {
    int timer;
};

vector<int> readInputWithCommas(string file){
    // Reads input file and return a vector<int> called input
	vector<int> input;
	ifstream inputFile(file);
	int number;
    char dummy;
	while (inputFile >> number){
		input.push_back(number);
        inputFile >> dummy;
	}
	inputFile.close();
	return input;
};

int main() {

    vector<int> input = readInputWithCommas("../input/input06.txt");

    vector<Fish> fishes;
    for (int i = 0; i < input.size(); i++) {
        fishes.push_back({input[i]});
    }

    Fish newfish{9};

    for (int day=1; day<81; day++) {
        for (int i = 0; i < fishes.size(); i++) {
            if (fishes[i].timer == 0) {            
                fishes.push_back(newfish);
                fishes[i].timer = 7;
            }
            fishes[i].timer--;
        }
    }

    cout << "Part 1 - The number of lanternfish after 80 days is "
         << fishes.size()
         << endl;

    return 0;
}