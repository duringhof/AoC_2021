#include "aoc_generic.hpp"

using namespace std;

int main() {

     vector<string> lines = readLines("../input/input08.txt");
     vector<vector<string>> input;
     for (auto line : lines) {
         input.push_back(split(split(line, '|')[1], ' '));
     }
     
     int counter = 0;
     for (auto input_line : input) {
         for (auto input_word : input_line) {
             if (input_word.size() == 2 || input_word.size() == 3 || input_word.size() == 4 || input_word.size() == 7) {
                 counter++;
             }
         }
     }

     cout << "Part 1 - The numbers 1, 7, 4 or 8 occur "
          << counter
          << " times."
          << endl;

     cout << "Part 2 - Not ready yet "
          // << 
          << endl;

    return 0;
}