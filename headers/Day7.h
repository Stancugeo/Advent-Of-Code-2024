#ifndef DAY7_H
#define DAY7_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#include <map>
using namespace std;
long long int result = 0;
void function1(int indx, vector<long long int>& list, bool& check, long long int eq, long long int& num) {
    if (indx == list.size()) {
        if (check && eq == num) {
            result += num;
            check   = false;
        }
        return;
    }

    function1(indx + 1, list, check,  eq                + list[indx], num);
    function1(indx + 1, list, check, (eq == 0 ? 1 : eq) * list[indx], num);



}



long long int concatenate(long long int num1, long long int num2) {
    int length = 0;
    long long int cpy_num2 = num2;
    while (cpy_num2 > 0) { cpy_num2 = cpy_num2 / 10;  length++; }
    num1 = num1 * pow(10, length) + num2;
    return num1;

}
void function2(int indx, vector<long long int>& list, bool& check, long long int eq, long long int& num) {
    if (indx == list.size()) {
        if (check && eq == num) {
            result += num;
            check = false;
        }
        return;
    }

    function2(indx + 1, list, check,  eq                + list[indx], num);
    function2(indx + 1, list, check, (eq == 0 ? 1 : eq) * list[indx], num);
    function2(indx + 1, list, check, concatenate(eq, list[indx])    , num);



}
void Day7_Part1() {
    ifstream file;
    file.open("resources/Day7.txt");
    string line;
    bool check;


    while (getline(file, line)) {
        check = true;
        long long int num = stoll(line.substr(0, line.find(':')));

        line = line.substr(line.find(':') + 2);
        vector<long long int> list;

        while (line.size() > 0) {

            if (line.find(' ') != string::npos) {
                list.push_back(stoll(line.substr(0, line.find(' '))));
                line = line.substr(line.find(' ') + 1);

            }
            else {

                list.push_back(stoll(line));
                line = "";
            }


        }


        function1(0, list, check, 0, num);




    }

    cout << result;
    file.close();
    return;


}
void Day7_Part2() {
    ifstream file;
    file.open("resources/Day7.txt");
    string line;
    bool check;


    while (getline(file, line)) {
        check = true;
        long long int num = stoll(line.substr(0, line.find(':')));

        line = line.substr(line.find(':') + 2);
        vector<long long int> list;

        while (line.size() > 0) {

            if (line.find(' ') != string::npos) {
                list.push_back(stoll(line.substr(0, line.find(' '))));
                line = line.substr(line.find(' ') + 1);

            }
            else {

                list.push_back(stoll(line));
                line = "";
            }


        }


        function2(0, list, check, 0, num);




    }

    cout << result;
    file.close();
    return;


}

#endif