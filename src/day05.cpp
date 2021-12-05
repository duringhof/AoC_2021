#include "aoc_generic.hpp"

using namespace std;

struct Point {
    int x;
    int y;
};

struct lineSegment {
    Point start;
    Point end;
};

vector<lineSegment> in2seg(vector<string> lines) {

    vector<lineSegment> segments;
    for (auto& line : lines) {
        stringstream ss(line);
        string s1, drop, s2;
        ss >> s1 >> drop >> s2;
        Point p1, p2;
        vector<string> s1_split = split(s1, ',');
        vector<string> s2_split = split(s2, ',');
        p1.x = stoi(s1_split[0]);
        p1.y = stoi(s1_split[1]);
        p2.x = stoi(s2_split[0]);
        p2.y = stoi(s2_split[1]);
        lineSegment seg;
        seg.start = p1;
        seg.end = p2;
        segments.push_back(seg);
    }

    return segments;
}

int countOverlaps(vector<vector<int>>& grid) {
    int count = 0;
    for (int y = 0; y < grid.size(); y++) {
        for (int x = 0; x < grid[y].size(); x++) {
            if (grid[y][x] > 1) {
                count++;
            }
        }
    }
    return count;
}

void printGrid(vector<vector<int>>& grid) {
    for (int y = 0; y < grid.size(); y++) {
        for (int x = 0; x < grid[y].size(); x++) {
            cout << grid[y][x] << " ";
        }
        cout << endl;
    }
}

void markGrid(vector<vector<int>>& grid, vector<lineSegment> segments, bool diagonalsOn) {
    for (auto segment : segments) {
        int x_min = min(segment.start.x, segment.end.x);
        int x_max = max(segment.start.x, segment.end.x);
        int y_min = min(segment.start.y, segment.end.y);
        int y_max = max(segment.start.y, segment.end.y);
        if (x_min != x_max && y_min != y_max) {
            if (!diagonalsOn) {
                continue;
            }
            if ((segment.start.x - segment.end.x)*(segment.start.y - segment.end.y) < 0) {
                for (int y = y_min; y <= y_max; y++) {
                    grid[y][x_max]++;
                    x_max--;
                }
            } else {
                for (int y = y_min; y <= y_max; y++) {
                    grid[y][x_min]++;
                    x_min++;
                }
            }
            // cout << "X: " << x_min << " " << x_max << " Y: " << y_min << " " << y_max << endl;
            // printGrid(grid);
            // cout << "----------------------------------------" << endl;
            continue;
        }
        for (int x = x_min; x <= x_max; x++) {
            for (int y = y_min; y <= y_max; y++) {
                grid[y][x]++;
            }
        }
        // cout << "X: " << x_min << " " << x_max << " Y: " << y_min << " " << y_max << endl;
        // printGrid(grid);
        // cout << "----------------------------------------" << endl;
    }
}

int main() {

    vector<string> input = readLines("../input/input05.txt");

    vector<lineSegment> segments = in2seg(input);

    vector<vector<int>> grid1(1000, vector<int>(1000, 0));
    vector<vector<int>> grid2(1000, vector<int>(1000, 0));

    markGrid(grid1, segments, false);
    cout << "Part 1 - " << "The number of points covered my 2 or more non-diagonal line segments is: "
         << countOverlaps(grid1) << endl;

    markGrid(grid2, segments, true);
    cout << "Part 2 - " << "The number of points covered my 2 or more line segments is: "
         << countOverlaps(grid2) << endl;

    return 0;
}