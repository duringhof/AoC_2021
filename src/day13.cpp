#include "aoc_generic.hpp"

using namespace std;

struct Point {
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) {}
};

bool findPoint(vector<Point>& points, int x, int y) {
    for (auto& point : points) {
        if (point.x == x && point.y == y) {
            return true;
        }
    }
    return false;
}

vector<Point> foldVertical(vector<Point>& oldpoints, int y) {
    vector<Point> newpoints;
    for (int i = 0; i < oldpoints.size(); i++) {
        if (oldpoints[i].y < y) {
            if (!findPoint(newpoints, oldpoints[i].x, oldpoints[i].y)) {
                newpoints.push_back(oldpoints[i]);
            }
        } else if (oldpoints[i].y > y) {
            if (!findPoint(newpoints,oldpoints[i].x,y - (oldpoints[i].y - y))) {
                newpoints.push_back(Point(oldpoints[i].x,y - (oldpoints[i].y - y)));
            }
        }
    }
    return newpoints;
}

vector<Point> foldHorizontal(vector<Point>& oldpoints, int x) {
    vector<Point> newpoints;
    for (int i = 0; i < oldpoints.size(); i++) {
        if (oldpoints[i].x < x) {
            if (!findPoint(newpoints, oldpoints[i].x, oldpoints[i].y)) {
                newpoints.push_back(oldpoints[i]);
            }
        } else if (oldpoints[i].x > x) {
            if (!findPoint(newpoints,x - (oldpoints[i].x - x),oldpoints[i].y)) {
                newpoints.push_back(Point(x - (oldpoints[i].x - x),oldpoints[i].y));
            }
        }
    }
    return newpoints;
}

int main() {

    vector<string> lines = readLines("../input/input13.txt");

    vector<Point> points;
    int it = -1;
    while (lines[it+1].size() > 0) {
        it++;
        points.push_back(Point(stoi(split(lines[it],',')[0]), stoi(split(lines[it],',')[1])));
    }

    vector<Point> newPoints;
    newPoints = points;

    for (int i = it+2; i < lines.size(); i++) {
        if (split(split(lines[i],' ')[2],'=')[0] == "x") {
            newPoints = foldHorizontal(newPoints,stoi(split(split(lines[i],' ')[2],'=')[1]));
        } else {
            newPoints = foldVertical(newPoints,stoi(split(split(lines[i],' ')[2],'=')[1]));
        }
        if (i == it+2) {
            cout << endl << "Part 1 - The number of visible points after the first fold is "
                 << newPoints.size() << endl << endl;;
        }
    }

    cout << "Part 2 - The 8 capital letter code is:"
         << endl << endl;

    int xmax = 0;
    int ymax = 0;

    for (auto& point : newPoints) {
        if (point.x > xmax) {
            xmax = point.x;
        }
        if (point.y > ymax) {
            ymax = point.y;
        }
    }

    int grid[xmax+1][ymax+1];

    for (auto& point : newPoints) {
        grid[point.x][point.y] = 1;
    }

    for (int y = 0; y <= ymax; y++) {
        for (int x = 0; x <= xmax; x++) {
            if (grid[x][y] == 1) {
                cout << "#";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    } 

    cout << endl << endl;

    return 0;
}