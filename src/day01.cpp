#include "aoc_generic.hpp"

using namespace std;

int slidingSum(vector<int>& v, int k) {
    int sum = v[k]+v[k-1]+v[k-2];
    return sum;
}

int main() {

    std::vector<int> depths = readInput("../input/input01.txt");

    int nrOfIncreases = 0;

    for (int i = 1; i < depths.size(); i++) {

        int diff = depths[i] - depths[i - 1];
        if (diff > 0) {
            nrOfIncreases++;
        }
    }

    cout << "Part 1: the number of times a depth measurement increases is " << nrOfIncreases << endl;

    nrOfIncreases = 0;

    for (int i = 3; i < depths.size(); i++) {

        int diff = slidingSum(depths,i) - slidingSum(depths, i - 1);
        if (diff > 0) {
            nrOfIncreases++;
        }
    }

    cout << "Part 2: the number of times the sum of measurements in a 3 sample sliding window increases is " << nrOfIncreases << endl;
    
    return 0;
}