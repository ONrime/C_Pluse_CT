#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*

N진수 게임

*/

string solution31(int n, int t, int m, int p) {
    string answer = "";
    string temp = "";
    int count = 1;
    
    for (int i = 0; i < t*m; i++) {
        int num = i;
        string temp2 = "";
        if (num == 0) temp.push_back('0');
        while (num > 0) {
            if (num % n < 10) {
                temp2 = (char)((num % n + (char)48)) + temp2;
            }
            else { temp2 = (char)((num % n + (char)55)) + temp2; }
            num /= n;
        }
        temp += temp2;
    }
    for (int i = 0; i < t* m; i++) {
        if (count == p) {
            answer += temp[i];
        }
        count++;
        if (count > m) count = 1;
    }
    cout << "answer: " << answer << endl;
    return answer;
}

/*int main()
{
    solution31(2, 4, 2, 1); // 0111
    solution31(16, 16, 2, 1); // 02468ACE11111111
    solution31(16, 16, 2, 2); // 13579BDF01234567
}*/
