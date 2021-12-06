#include "aoc_generic.hpp"

using namespace std;

long countFishes(vector<long> fishcounter) {
    long sum = 0;
    for (long i = 0; i < fishcounter.size(); i++) {
        sum += fishcounter[i];
    }
    return sum;
}

int main() {

    vector<int> input = readInputWithCommas("../input/input06.txt");

    vector<long> fishcounter(9, 0);

    for (int i = 0; i < input.size(); i++) {
        fishcounter[input[i]]++;
    }

    long newborns = 0;
    long res_part1, res_part2 = 0;

    for (int day=1; day<257; day++) {
        newborns = fishcounter[0];
        for (int i = 0; i < 8; i++) {
            fishcounter[i] = fishcounter[i+1];
        }
        fishcounter[8] = newborns;
        fishcounter[6] += newborns;
        if (day == 80) {
            res_part1 = countFishes(fishcounter);
        }
        if (day == 256) {
            res_part2 = countFishes(fishcounter);
        }
    }

    cout << "Part 1 - The number of lanternfish after 80 days is "
         << res_part1
         << endl;

    cout << "Part 2 - The number of lanternfish after 256 days is "
         << res_part2
         << endl;

    return 0;
}