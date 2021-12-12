#include "aoc_generic.hpp"

using namespace std;

vector<char> diffStrings(const string& a, const string& b) {
     vector<char> diff;
     bool found = false;
     for (auto c : a) {
          found = false;
          for (auto d : b) {
               if (c == d) {
                    found = true;
               }
          }
          if (!found) {
               diff.push_back(c);
          }
     }
     for (auto c : b) {
          found = false;
          for (auto d : a) {
               if (c == d) {
                    found = true;
               }
          }
          if (!found) {
               diff.push_back(c);
          }
     }
     return diff;
}

int decodeOutput(vector<string> output, vector<string> input) {
     sort(input.begin(), input.end(), []
          (const string& first, const string& second) {
               return first.size() < second.size();
          });
     int res = 0;
     for (int i = 1; i < 5; i++) {
          switch (output[i].size()) {
               case 2: // 1
                    res+=1*pow(10, 4-i);
                    break;
               case 3: // 7
                    res+=7*pow(10, 4-i);
                    break;
               case 4: // 4
                    res+=4*pow(10, 4-i);
                    break;
               case 5: // 2, 3 or 5
                    if (diffStrings(output[i], input[2]).size() == 5) {
                         res+=2*pow(10, 4-i); // 2
                    } else if (diffStrings(output[i], input[0]).size() == 3) {
                         res+=3*pow(10, 4-i); // 3
                    } else {
                         res+=5*pow(10, 4-i); // 5
                    }
                    break;
               case 6: // 0, 6 or 9
                    if (diffStrings(output[i], input[2]).size() == 2) {
                         res+=9*pow(10, 4-i); // 9
                    } else if (diffStrings(output[i], input[0]).size() == 4) {
                         res+=0*pow(10, 4-i); // 0
                    } else {
                         res+=6*pow(10, 4-i); // 6
                    }
                    break;
               case 7: // 8
                    res+=8*pow(10, 4-i);
                    break;
          }
     }
     return res;
}

int main() {

     vector<string> lines = readLines("../input/input08.txt");
     vector<vector<string>> input, output;
     for (auto line : lines) {
         input.push_back(split(split(line, '|')[0], ' '));
         output.push_back(split(split(line, '|')[1], ' '));
     }
     
     int counter = 0;
     for (auto output_line : output) {
         for (auto output_word : output_line) {
             if (output_word.size() == 2 || output_word.size() == 3 || output_word.size() == 4 || output_word.size() == 7) {
                 counter++;
             }
         }
     }

     int answer = 0;
     for (int i = 0; i < output.size(); i++) {
          answer += decodeOutput(output[i], input[i]);
     }

     cout << "Part 1 - The numbers 1, 7, 4 or 8 occur "
          << counter
          << " times."
          << endl;

     cout << "Part 2 - The sum of decoded output values is "
          << answer 
          << endl;

    return 0;
}