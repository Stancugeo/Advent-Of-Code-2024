#ifndef DAY1_H
#define DAY1_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
void Day1_Part1() {
	ifstream file;
	file.open("Day1.txt");
	string line;
	vector<int> num1, num2;

	while (getline(file , line)){
		num1.push_back(stoi(line.substr(0 , line.find(' '))));
		num2.push_back(stoi(line.substr(line.find(' ') + 1, line.length())));

	}
	sort(num1.begin(), num1.end());
	sort(num2.begin(), num2.end());
	int n = num1.size();
	int res = 0;
	for (int i = 0; i < n; i++) {
		int num = abs(num1[i] - num2[i]);
		res += num;
	}
	cout << res;

	return;
}
void Day1_Part2() {
	ifstream file;
	file.open("Day1.txt");
	string line;
	unordered_map <int, int> num1, num2;


	while (getline(file, line)) {
		num1[stoi(line.substr(0, line.find(' ')))] += 1;
		num2[stoi(line.substr(line.find(' ') + 1, line.length()))] += 1;

	}
	int res = 0;
	for (pair<int, int> number : num1) {
		int n = number.first;
		int cnt1 = number.second;
		int cnt2 = num2[n];
		res += cnt1 * cnt2 * n;


	}
	cout << res;

	return;


}
#endif