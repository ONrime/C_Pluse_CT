#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<char> line1;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution3(int n, vector<string> data) {
    int answer = 0;
    line1 = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
    do {
        int i = -1;
        int checkend = line1.size();
        bool isfound = false;
        do {
            i++;
            for (int j = 0; j < checkend; j++) {
                if (data[i][0] == line1[j] || data[i][2] == line1[j]) {
                    if (isfound) {
                        isfound = false;
                        if (i == data .size()-1) {
                            answer++;
                        }
                        break;
                    }
                    isfound = true;
                    if (data[i][3] == '=') {
                        j += (data[i][4] - '0'); // +1은 for문에서
                        checkend = j + 2;
                    }
                    else if (data[i][3] == '<') {
                        checkend = j + (data[i][4] - '0')+1;
                    }
                    else if (data[i][3] == '>') {
                        j += (data[i][4] - '0') + 1;
                    }
                }
            }
            checkend = line1.size();
        } while (!isfound && i < data.size() - 1);
    } while (next_permutation(line1.begin(), line1.end()));
    return answer;
}

/*int main()
{
    cout << "answer: " << solution3(2, { "N~F=0", "R~T>2" }) << "\n"; // 3648
    cout << "answer: " << solution3(2, { "M~C<2", "C~M>1" }) << "\n"; // 0
}*/

/*

단체사진 찍기

*/