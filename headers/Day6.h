#ifndef DAY6_H
#define DAY6_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#include <map>
using namespace std;

void Day6_Part1() {
    ifstream file;
    file.open("resources/Day6.txt");
    string line;
    vector<string> hmap;
    int x_guard = 0, y_guard = 0;

    int ycount = 0;
    while (getline(file, line)) {
        cout << line << endl;

        hmap.push_back(line);
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '^') { y_guard = ycount, x_guard = i; }
        }

        ycount += 1;
    }
    cout << y_guard << " " << x_guard << endl;

    vector<pair<int, int>> dir{ {-1 , 0} , {0 , 1} , {1 , 0} , {0 , -1} };
    int i = 0;
    long long int res = 0;

    while (x_guard >= 0 && x_guard < hmap[0].size() &&
           y_guard >= 0 && y_guard < hmap.size()) {


        
        if (hmap[y_guard][x_guard] == '#') {
            y_guard -= dir[i].first;
            x_guard -= dir[i].second;
            i = (i + 1) % 4;

        }
        else { hmap[y_guard][x_guard] = 'X'; }
        
        y_guard += dir[i].first;
        x_guard += dir[i].second;

    }

    return;
}
void Day6_Part2() {




}


#endif