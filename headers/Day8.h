#ifndef DAY8_H
#define DAY8_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#include <map>
using namespace std;

void Day8_Part1() {
    int res = 0;

    ifstream file;
    file.open("resources/Day8.txt");
    string line;
    vector<string> hmap;
    while (getline(file, line)) hmap.push_back(line);

    unordered_map<char, vector<pair<int, int>>> coord;

    for (int i = 0; i < hmap.size(); i++) {
        for (int j = 0; j < hmap[0].size(); j++) {

            if (hmap[i][j] != '.') { coord[hmap[i][j]].push_back({ i , j }); }
        }
    }
        
        
        
        for (auto ipair : coord) {

        char let = ipair.first;


        vector<pair<int, int>> ilist = ipair.second;

        for (int i = 0; i < ilist.size(); i++) {

            int ix = ilist[i].first;
            int iy = ilist[i].second;


            for (int j = 0; j < ilist.size(); j++) {
                if (i == j) continue;

                int jx = ilist[j].first;
                int jy = ilist[j].second;


                int middle_x = ix, middle_y = iy, fside_x = jx, fside_y = jy;
                int sside_x = 2 * middle_x - fside_x;
                int sside_y = 2 * middle_y - fside_y;



                if (sside_x < 0 || sside_x >= hmap.size() ||
                    sside_y < 0 || sside_y >= hmap[0].size()) continue;

                hmap[sside_x][sside_y] = 'X';



            }


        }



    }
    for (int i = 0; i < hmap.size(); i++) {
        for (int j = 0; j < hmap[0].size(); j++) {
            if (hmap[i][j] == 'X') res += 1;
        }


    }
    cout << res << " ";


}

#endif