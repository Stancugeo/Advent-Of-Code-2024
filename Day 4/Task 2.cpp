#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <vector>
using namespace std;
int main()
{
    ifstream f;
    f.open("FILE.txt");
    string str;
    int res = 0;

    unordered_set<int>list1;
    vector<int>freqlist(221 , 1);
    int i = 1;
    while(getline(f , str)){
        str = str.substr(str.find(':') + 1, str.size() - (str.find(':') + 1)) + " ";
        int number = 0;
        int num_cards = 0;
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
                if(list1.find(number) != list1.end()){ num_cards ++; }
                number = 0;
            }
        }
        for(int j = i + 1; j <= min(i + num_cards , 220); j ++){ freqlist[j] += freqlist[i]; }
        i ++;
        list1.clear();
    }
    for(int j = 1 ; j <= 220; j ++) res += freqlist[j];
    cout << res << " ";
    f.close();
    return 0;

}
