#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 0;
    bool check;
    for (int i = 0; i < dic.size(); i++) {
        check = true;
        for (int j = 0; j < spell.size(); j++) {
            if (dic[i].find(spell[j]) == string::npos) {
                check = false;
                break;
            }
        }
        if (check == true) {
            answer = 1;
            return answer;
        }
    }
    answer = 2;
    return answer;
}