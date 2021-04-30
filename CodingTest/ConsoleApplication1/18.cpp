#include <string>
#include <vector>
#include <iostream>

using namespace std;

int min_num = 10;
void show_n4(int current_num, int N, int number, int count) {
    if (count > 8) {
        return;
    }
    if (current_num == number) {
        if (min_num > count) { 
            min_num = count;
        }
        return;
    }
    int tempN = 0;
    for (int i = 0; i + count < 9; i++) {
        tempN = (tempN * 10) + N;
        show_n4(current_num + tempN, N, number, count + 1 + i);
        show_n4(current_num - tempN, N, number, count + 1 + i);
        show_n4(current_num * tempN, N, number, count + 1 + i);
        show_n4(current_num / tempN, N, number, count + 1 + i);
    }
}

int solution(int N, int number) {
    int answer = 0;
    int count = 0;
    show_n4(0, N, number, count);
    return min_num;
}

int main()
{
    cout << "answer: " << solution(5, 12) << "\n"; // 4
    cout << "answer: " << solution(2, 11) << "\n"; // 3
}

/*

N으로 표현

문제 설명
아래와 같이 5와 사칙연산만으로 12를 표현할 수 있습니다.

12 = 5 + 5 + (5 / 5) + (5 / 5)
12 = 55 / 5 + 5 / 5
12 = (55 + 5) / 5

5를 사용한 횟수는 각각 6,5,4 입니다. 그리고 이중 가장 작은 경우는 4입니다.
이처럼 숫자 N과 number가 주어질 때, N과 사칙연산만 사용해서 표현 할 수 있는 방법 중 N 사용횟수의 최솟값을 return 하도록 solution 함수를 작성하세요.

제한사항
N은 1 이상 9 이하입니다.
number는 1 이상 32,000 이하입니다.
수식에는 괄호와 사칙연산만 가능하며 나누기 연산에서 나머지는 무시합니다.
최솟값이 8보다 크면 -1을 return 합니다.
입출력 예
N	number	return
5	12	4
2	11	3
입출력 예 설명
예제 #1
문제에 나온 예와 같습니다.

예제 #2
11 = 22 / 2와 같이 2를 3번만 사용하여 표현할 수 있습니다.

*/

/*int show_n(int N, int number, int& count) {
    if (number == N) {
        return count;
    }
    if (count > 8) return count = 0;
    count++;
    count = show_n(N + N, number, count);
    count = show_n(N - N, number, count);
    count = show_n(N / N, number, count);
    count = show_n(N * N, number, count);
    count = show_n((N * 10) + N, number, count);

    return count;
}*/



/*int string_num(string a) {
    istringstream ss(a);
    string stringBuffer;
    vector<string> x;
    while (getline(ss, stringBuffer, ' ')) {
        x.push_back(stringBuffer);
        //cout << stringBuffer << " ";
    }

    queue<int> num;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] == "+") x[i-1] +
        else if (x[i] == "-");
        else if (x[i] == "*");
        else if (x[i] == "/");
        else {
        }
    }

}*/

/*void show_n3(string current_num, int N, int number, int& count) {
    if (number == stoi(current_num)) {
        return;
    }
    if (count > 2) {
        //count--;
        return;
    }
    else {
        count++;
    }
    show_n3(current_num + " + N", N, number, count);
    show_n3(current_num + " - N", N, number, count);
    show_n3(current_num + " * N", N, number, count);
    show_n3(current_num + " / N", N, number, count);
    show_n3(current_num + N, N, number, count);
    count--;

    return;
}*/

/*void show_n2(int current_num, int N, int number, int& count) {
    int tempN = 0;
    for (int i = 0; i + count < 9; i++) {
        if (number == current_num) {
            if (minN < count) minN = count;
            return;
        }
        if (count > 8) {
            //count--;
            return;
        }
        else {
            count++;
        }
        tempN = (tempN * 10) + N;
        show_n2(current_num + tempN, N, number, count);
        show_n2(current_num - tempN, N, number, count);
        show_n2(current_num / tempN, N, number, count);
        show_n2(current_num * tempN, N, number, count);
        count--;
    }
    return;
}*/