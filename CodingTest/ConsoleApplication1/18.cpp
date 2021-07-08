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

/*int main()
{
    cout << "answer: " << solution(5, 12) << "\n"; // 4
    cout << "answer: " << solution(2, 11) << "\n"; // 3
}*/

/*

N으로 표현

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