#include "aoc_generic.hpp"

using namespace std;

int calcFuel(int start, int target, bool progressive) {
    int fuel = 0;
    if (abs(target - start) > 0) {
        for (int i = 0; i < abs(target - start); i++) {
            fuel += 1 + progressive*i;
        }
    }
    return fuel;
}

int highestValue(vector<int>& v) {
    int max = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    return max;
}

int optimalFuel(vector<int>& v, bool progressive) {
    int min_fuel = INT_MAX;
    int fuel;
    for (int i = 0; i < highestValue(v); i++) {
        fuel = 0;
        for (int j = 0; j < v.size(); j++) {
            fuel += calcFuel(v[j], i, progressive);
        }
        min_fuel = (fuel < min_fuel ? fuel : min_fuel);
    }
    return min_fuel;
}

int main() {

    vector<int> input = readInputWithCommas("../input/input07.txt");

    cout << "Part 1 - The total fuel cost for optimally aligning all crab submarines is "
         << optimalFuel(input, false)
         << endl;

    cout << "Part 2 - The corrected fuel cost for optimally aligning all crab submarines is "
         << optimalFuel(input, true)
         << endl;

    return 0;
}