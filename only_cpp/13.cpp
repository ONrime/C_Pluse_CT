#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;

int solution(string name) {
    int answer = 0;

    int i = 0;
    string temp(name.size(), 'A');
    while (true) {
        temp[i] = name[i];
        int num = (int)name[i] - 65;
        if (num > 13) { num = abs(26 - num); }
        answer += num;
        if (temp == name) { break; }

        for (int j = 1; j < name.size(); j++) {
            if (name[(i + j) % name.size()] != temp[(i + j) % name.size()]) {
                i = (i + j) % name.size();
                answer += j;
                break;
            }
            else if (name[(i + name.size() - j) % name.size()] != temp[(i + name.size() - j) % name.size()]) {
                i = (i + name.size() - j) % name.size();
                answer += j;
                break;
            }
        }
    }
    return answer;
}

/*int main()
{
    cout << "answer: " << solution("JAZ") << endl; // 11
    cout << "answer: " << solution("JEROEN") << endl; // 56
    cout << "answer: " << solution("JAN") << endl; // 23
    cout << "answer: " << solution("ABAAAAABAB") << endl; // 8
}*/

/*

Á¶ÀÌ½ºÆ½

*/
