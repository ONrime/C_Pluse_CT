#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution25(int n) {
    string answer = "";
    while (n > 0) {
        int pushNum = n % 3; // 끝 자리
        if (pushNum == 0) pushNum = 4;
        answer = to_string(pushNum) + answer;
        n /= 3; // 다음
        if (pushNum == 4) n--;
    }
    cout << "answer: " << answer << endl;

    return answer;
}

/*int main()
{
    solution25(39);
    solution25(10);
    solution25(11);
    solution25(12);
    solution25(500000000);
}*/

/*

124 나라의 숫자

*/