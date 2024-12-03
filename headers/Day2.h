#ifndef DAY2_H
#define DAY2_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
vector<int> hfile{ 1, 2 , 3 };
bool IncreasePart(vector<int> list) {

	bool inc = true;
	for (int i = 1; i < list.size() && inc; i++) {
		if (find(hfile.begin(), hfile.end(), list[i] - list[i - 1]) == hfile.end()) inc = false;

	}
	return inc;



}
bool DecreasePart(vector<int> list) {
	bool dec = true;
	for (int i = 1; i < list.size() && dec; i++) {
		if (find(hfile.begin(), hfile.end(), list[i - 1] - list[i]) == hfile.end()) dec = false;
	}
	return dec;

}

void Day2_Part1() {
	ifstream file;
	file.open("Day2.txt");
	string line;
	int res = 0;
	

	while (getline(file, line)) {
		
		vector<int>list;

		while (line.size() > 0) {
			int num = 0;
			if (line.find(' ') != string::npos) {
				num = stoi(line.substr(0, line.find(' ')));
				line = line.substr(line.find(' ') + 1);
			}
			else {
				num = stoi(line);
				line = "";
			}
			list.push_back(num);
		} 

		if (IncreasePart(list) || DecreasePart(list)) res++;


	}
	cout << res;


	return;
}
void Day2_Part2() {
	ifstream file;
	file.open("Day2.txt");
	string line;
	int res = 0;
	vector<int> hfile{ 1, 2 , 3 };

	while (getline(file, line)) {

		vector<int>list;

		while (line.size() > 0) {
			int num = 0;
			if (line.find(' ') != string::npos) {
				num = stoi(line.substr(0, line.find(' ')));
				line = line.substr(line.find(' ') + 1);
			}
			else {
				num = stoi(line);
				line = "";
			}
			list.push_back(num);
		}
		// brute force , i didnt find optimal solution 

		if (IncreasePart(list) || DecreasePart(list)) res += 1;
		else {
			for (int i = 0; i < list.size(); i++) {
				vector<int> hlist = list;
				hlist.erase(hlist.begin() + i);
				if (IncreasePart(hlist) || DecreasePart(hlist)) {
					res += 1;
					break;
				}

			}
		}



	}
	cout << res;


	return;

}
#endif