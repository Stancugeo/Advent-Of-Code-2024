#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
using namespace std;
int main()
{
    ifstream f;
    f.open("file.txt");
    string str;
    unordered_set<int>list1;
    int res = 0;
    while(getline(f , str)){
        str = str.substr(str.find(':') + 1, str.size() - (str.find(':') + 1)) + " ";
        int number = 0;
        int points = 1;
        int total_points = 0;
        for(int i = 0 ; i < str.find('|'); i ++){
            if(isdigit(str[i])){ number = number * 10 + (str[i] - '0');
            }else if(number != 0){
                list1.insert(number);
                number = 0;
            }
        }
        for(int i = str.find('|') + 1; i < str.size(); i ++){
            if(isdigit(str[i])){ number = number * 10 + (str[i] - '0');
            }else{
                if(list1.find(number) != list1.end()){
                    total_points = points;
                    points *= 2;
                }
                number = 0;
            }
        }
        res += total_points;
        list1.clear();
    }
    cout << res;
    f.close();
    return 0;

}
