#ifndef DAY4_H
#define DAY4_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#include <map>
using namespace std;

long long int res = 0;

string XMAS = "XMAS";

vector<vector<pair<int, int>>> offset = {

	{{ 0, 0},{ 0, 1},{ 0, 2},{ 0, 3}},// right
	{{ 0, 0},{-1, 0},{-2, 0},{-3, 0}},// up
	{{ 0, 0},{ 0,-1},{ 0,-2},{ 0,-3}},// left
	{{ 0, 0},{ 1, 0},{ 2, 0},{ 3, 0}},// down
	{{ 0, 0},{ 1, 1},{ 2, 2},{ 3, 3}},// right-down
	{{ 0, 0},{-1, 1},{-2, 2},{-3, 3}},// right-up
	{{ 0, 0},{-1,-1},{-2,-2},{-3,-3}},// left-up
	{{ 0, 0},{ 1,-1},{ 2,-2},{ 3,-3}} // left-down

};

void dfs(int i, int j, vector<string>& matrix ) {

	for (int dir = 0; dir < offset.size(); dir++) {
		bool check = true;
		for (int pos = 0; pos < offset[dir].size(); pos++) {
			int x = i + offset[dir][pos].first;
			int y = j + offset[dir][pos].second;
			
			if ( (x < 0 || x >= matrix.size())    ||
				 (y < 0 || y >= matrix[0].size()) ||
				 (matrix[x][y] != XMAS[pos]) ) {
				check = false;
				break;
			}


		}
		if (check) res += 1;


	}
	return;

}

void Day4_Part1() {

	ifstream file;
	file.open("resources/Day4.txt" );


	vector<string> matrix;
	string line;

	while(getline(file , line)) matrix.push_back(line);


	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			if (matrix[i][j] == 'X') dfs(i, j, matrix);
		}

	}
	cout << res;


	file.close();


}
void Day4_Part2() {

	ifstream file;
	file.open("resources/Day4.txt");


	vector<string> matrix;
	string line;

	while (getline(file, line)) matrix.push_back(line);


	vector<pair<int, int>> offset2 = {
		{-1 , -1} , {1 , 1} ,
		{-1 , 1}  , {1 , -1}

	};

	unordered_set<string> hash = { "MS" , "SM" };


	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			if (matrix[i][j] == 'A') {

				string diag1 = "", diag2 = "";


				for (int p = 0; p < 2; p++) {
					int x = i + offset2[p].first, y = j + offset2[p].second;
					if (x < 0 || x >= matrix.size())    break;
					if (y < 0 || y >= matrix[0].size()) break;
					diag1 += matrix[x][y];


				}
				for (int p = 2; p < 4; p++) {
					int x = i + offset2[p].first, y = j + offset2[p].second;
					if (x < 0 || x >= matrix.size())    break;
					if (y < 0 || y >= matrix[0].size()) break;
					diag2 += matrix[x][y];
				}

				cout << diag1 << " " << diag2 << endl;

				if (hash.find(diag1) != hash.end() && hash.find(diag2) != hash.end()) {
					res += 1;
				}










			}
		}

	}
	cout << res;


	file.close();


}

#endif