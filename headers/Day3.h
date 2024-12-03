#ifndef DAY3_H
#define DAY3_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>


using namespace std;
int Calculate(string line) {
	long long int res = 0;

	while (1) {

		if (line.find("mul(") == string::npos) break;
		line.erase(0, line.find("mul(") + 4);

		string number1 = "";
		int i = 0;
		while (i < line.size()) {
			if (line[i] >= '0' && line[i] <= '9') number1 += line[i];
			else if (line[i] == ',') break;
			else {
				number1 = "";
				break;
			}
			i += 1;
		}
		if (number1 == "") continue;

		string number2 = "";
		int j = i + 1;
		while (j < line.size()) {
			if (line[j] >= '0' && line[j] <= '9') number2 += line[j];
			else if (line[j] == ')') break;
			else {
				number2 = "";
				break;
			}
			j += 1;

		}
		if (number2 == "") continue;
		res += stol(number1) * stol(number2);

	}
	return res;


}
void Day3_Part1() {
	ifstream file;
	file.open("Day3.txt");
	string hline = "";
	string line  = "";


	while (getline(file, hline)) line += hline;
	cout << Calculate(line);

	file.close();


}
void Day3_Part2() {
	ifstream file;
	file.open("Day3.txt");
	string hline = "";
	string line = "";
	long long int res = 0;

	bool T_do = true;


	while (getline(file, hline)) {

		while (hline.size() > 0) {
			int indx = -1;

			if (hline.find("do()") != -1 && hline.find("don't()") != -1)
				indx = min(int(hline.find("do()")), int(hline.find("don't()")));


			else if (hline.find("do()")    != -1) indx = int(hline.find("do()"));
			else if (hline.find("don't()") != -1) indx = int(hline.find("don't()"));


			if (indx == -1) {
				line = hline;
				if (T_do) res += Calculate(line);
				hline = "";
			}
			else {

				line = hline.substr(0, indx);
				if (T_do) res += Calculate(line);

				if (hline.find("do()")    != -1 && indx == hline.find("do()"))    {
					T_do = true;
					hline = hline.substr(hline.find("do()") + 4);
				}

				if (hline.find("don't()") != -1 && indx == hline.find("don't()")) {
					T_do = false;
					hline = hline.substr(hline.find("don't()") + 7);

				}
			}

			

		}

	}
	cout << res;

	file.close();


}

#endif