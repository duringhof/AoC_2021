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

    vector<long> fishcount(9, 0);

    vector<Fish> fishes;

    for (int i = 0; i < input.size(); i++) {
        fishes.push_back({input[i]});
        fishcount[input[i]]++;
    }

    Fish newfish{9};

    for (int day=1; day<81; day++) {
        for (long i = 0; i < fishes.size(); i++) {
            if (fishes[i].timer == 0) {            
                fishes.push_back(newfish);
                fishes[i].timer = 7;
            }
            fishes[i].timer--;
        }
    }

    long totalfish = 0;
    long newfishcounter = 0;

    for (int day=1; day<257; day++) {
        newfishcounter = fishcount[0];
        for (int i = 0; i < 8; i++) {
            fishcount[i] = fishcount[i+1];
        }
        fishcount[8] = newfishcounter;
        fishcount[6]+=newfishcounter;
        totalfish=0;

    }

    totalfish=0;
    for (int i = 0; i < 9; i++) {
        totalfish += fishcount[i];
    }
    
    cout << "Part 1 - The number of lanternfish after 80 days is "
         << fishes.size()
         << endl;

    cout << "Part 2 - The number of lanternfish after 256 days is "
         << totalfish
         << endl;



    return 0;
}