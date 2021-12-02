#include "aoc_generic.hpp"

using namespace std;

struct Instruction {
    string command;
    int value;
};

struct State {
    int pos;
    int depth;
    int aim;
};

vector<Instruction> readInstructions(vector<string> lines) {
    vector<Instruction> instructions;
    for (auto line : lines) {
        stringstream ss(line);
        Instruction instruction;
        ss >> instruction.command;
        ss >> instruction.value;
        instructions.push_back(instruction);
    }
    return instructions;
}

int main() {

    vector<string> lines = readLines("../input/input02.txt");
    vector<Instruction> instructions = readInstructions(lines);

    int forward = 0;
    int depth = 0;
    int aim = 0;

    State part1 = {0, 0, 0};
    State part2 = {0, 0, 0};

    for (Instruction instruction : instructions) {
        if (instruction.command == "forward") {
            part1.pos += instruction.value;
            part2.pos += instruction.value;
            part2.depth += instruction.value* part2.aim;
        } else if (instruction.command == "down") {
            part1.depth += instruction.value;
            part2.aim += instruction.value;
        } else if (instruction.command == "up") {
            part1.depth -= instruction.value;
            part2.aim -= instruction.value;
        }
    }

    cout << "Part 1 - The submarine's depth multiplied by its position is: " << part1.depth * part1.pos << endl;
    cout << "Part 2 - The submarine's depth multiplied by its position is: " << part2.depth * part2.pos << endl;
    
    return 0;
}