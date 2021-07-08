#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string solution3(string number, int k) {
    string answer = "";
    int line = number.size() - k;
    int max_i = -1;
    for (int i = 0; i < number.length() - k; i++) {
        int max = 0;
        for (int j = max_i + 1; j <= k + i; j++) {
            if (max < number[j]- '0') {
                max_i = j;
                max = number[j] - '0';
            }
        }
        answer += to_string(max);
    }
    cout << "answer!: " << answer << endl;
    return answer;
}

/*int main()
{
    solution3("1924", 2); // 94
    //solution3("1904", 2); // 94
    //solution3("1231234", 3); // 3234
    //solution3("4177252841", 4); // 775841
    //solution3("75284", 2); // 78
    //solution3("4175284", 4); // 784
    solution3("87654321", 3); // 87654
    //solution3("648245365", 7); // 86
    //solution3("845365", 4); // 86
}*/

/*

큰 수 만들기

*/




/*

여러 가지를 만든 끝에 도저히 안되서 다른 코드를 참고 했다.
오랜 시간이 걸린 이유를 뽑자면 나는 탐욕법 답게 욕심이 과한 코드를 만들었다.
한번 돌 때 계산하는 형태의 코드를 만들었는데 이게 메모리를 초과하는 문제가 있었다.
너무 한번에 돌려서 풀려고 하는 코드를 만들기 보다는 변수나 함수를 생각하면서 푸는 습과을 가져야 된다.

/*string solution(string number, int k) {
    string answer = "";
    string a = number;
    vector<int> temp;
    int n = a.size() - k;
    for (int i = 0; i < n; i++) {
        temp.push_back(1);
    }
    for (int i = 0; i < a.size() - n; i++) {
        temp.push_back(0);
    }
    int max = 0;
    do {
        string num;
        for (int i = 0; i < a.size(); i++) {
            if (temp[i] == 1) {
                num.push_back(a[i]);
            }
        }
        int num_ = stoi(num);
        if (max < num_) {
            max = num_;
        }
    } while (prev_permutation(temp.begin(), temp.end()));

    answer = to_string(max);
    return answer;
}

string solution2(string number, int k) {
    string answer = "";
    string a = number;
    answer = number;
    int cut = answer.size() - k;
    int min = 10;
    int min_ = 0;
    for (int i = 0; i < answer.size(); i++) {
        min = 10;
        for (int j = 0; j < k; j++) {
            int num = answer[j] - '0';
            if (min > num) {
                min = num;
                min_ = j;
            }
        }
        answer.erase(answer.begin() + min_);
        if (answer.size() == cut) break;
    }
    cout << "answer: " << 7/2 << endl;
    return answer;
}

string solution3(string number, int k) {
    string answer = "";
    string answer2 = number;
    answer = number;
    int line = number.size() - k;

    sort(answer.begin(), answer.end());
    sort(answer2.begin(), answer2.end());
    auto it_del=unique(answer.begin(), answer.end());
    int full_size = answer.size();

    answer.erase(it_del, answer.end());
    cout << "answer: " << answer << endl;
    //cout << "answedr: " << number.size()<<" " << k << endl;

    int m = full_size - answer.size();
    //cout << "full_size: " << full_size << endl;
    int cut = full_size /2;
    //k = (k - m);
    //cut > k ? cut = k : cut = k;
    m>k?
    m == 0 ? cut = k : cut = (answer.size() / 2) - m;

    for (int i = 0; i < number.size(); i++) {
        if (number[i] < answer2[cut]) {
            number.erase(number.begin() + i);
            i--;
        }
        if (number.size() == line) break;
    }
    cout << "answer!!: " << number << endl;
    return number;
}

string solution3(string number, int k) {
    string answer = "";
    answer = number;
    int line = number.size() - k;

    sort(answer.begin(), answer.end());
    int full_size = answer.size();
    cout << "answer: " << answer << endl;

    int m = full_size - answer.size();
    int cut = k-1;

    for (int i = 0; i < number.size(); i++) {
        int x=answer[cut]-'0';
        if (number[i] - '0' <= answer[cut] - '0') {
            number.erase(number.begin() + i);
            i--;
        }
        if (number.size() == line) break;
    }
    cout << "answer!!: " << number << endl;
    return number;
}

bool comp(int a, int b) {
    return a > b;
}

string solution3(string number, int k) {
    string answer = "";
    answer = number;
    int line = number.size() - k;

    sort(answer.begin(), answer.end(), comp);
    int full_size = answer.size();
    cout << "answer: " << answer << endl;

    int m = full_size - answer.size();
    //int cut = k-1;
    int cut = (answer.size()/2)+1;
    int i = 0;
    int  now = number.size();
    while (number.size() != line) {
        int x = answer[cut] - '0';
        int y = number[i] - '0';
        if (number[i] - '0' <= answer[cut] - '0') {
            number.erase(number.begin() + i);
            i--;
        }
        i++;
        if (i == number.size()) {
            cut -= 1;
            i = 0;
        }
    }
    cout << "answer!!: " << number << endl;
    return number;
}
string solution3(string number, int k) {
    string answer = "";
    answer = number;
    int line = number.size() - k;

    sort(answer.begin(), answer.end(), comp);
    int full_size = answer.size();
    cout << "answer: " << answer << endl;

    int m = full_size - answer.size();
    //int cut = k-1;
    //int cut = (answer.size() / 2) + 1;
    int cut = (answer.size() - k) ;
    int i = 0;
    for (auto it = answer.begin(); it != answer.end(); it++) {
        int x = *it - '0';
        int y = number[i] - '0';
        if (*it - '0' > number[i] - '0') {
            number.erase(number.begin() + i);
            i--;
        }
        i++;
        if (number.size() == line) break;
    }


    int j = 0;
    int  now = number.size();
    while (number.size() != line) {
        int x = answer[cut] - '0';
        int y = number[j] - '0';
        if (number[j] - '0' <= answer[cut] - '0') {
            number.erase(number.begin() + j);
            j--;
        }
        j++;
        if (j == number.size()) {
            cut -= 1;
            j = 0;
        }
    }
    cout << "answer!!: " << number << endl;
    return number;

    for (int i = 0; i < number.size(); i++) {
        int x = answer[i] - '0';
        int y = number[i-l] - '0';
        if (answer[i] - '0' > number[i-l] - '0') {
            number.erase(number.begin() + i-l);
            l++;
        }
        if (number.size() == line) break;
    }
}

string ssos(string num, int k, int& c) {
    int max = num[0] - '0';
    int back = 10;
    string t;
    for (int i = 0; i < num.size(); i++) {
        if (num[i] - '0' > max) {  // max를 오버 할 때
            max = num[i] - '0';
            if (c + t.size() < k) {
                c += t.size();
                t.clear(); ;
            }
            else {
                t = ssos(t, k, c);
            }
            back = num[i] - '0';
            i--;
        }
        else {  // max 보다 낮을 때
            if (num[i] - '0' > back) {  // 순서대로 진행이 안될 떄
                //int cc = -1;
                while (true) {
                    t.pop_back();
                    c++;
                    //cc++;
                    if (c == k || num[i] < t.back()) {
                        back = num[i] - '0';
                        //i--;
                        t.push_back(num[i]);
                        break;
                    }
                }
            }
            else {  // 순서대로 진행 될 때
                t.push_back(num[i]);
                back = num[i] - '0';
            }
        }
        if (c == k) {
            t += num.substr(i + 1, num.size());
            break;
        }
    }
    while (c != k) {
        t.pop_back();
        c++;
    }
    return t;
}

void ssos2(string& num, int k, int& c) {
    int max = num[0] - '0';
    int i = 0;
    while (i < num.size()) {
        if (num[i] - '0' > max) {  // max를 오버 할 때
            max = num[i] - '0';
            if (c + (i) < k) {
                c += (i);
                num.erase(num.begin(), num.begin() + i);
                i = 0;
            }
            else {
                while (c != k) {
                    num.erase(num.begin() + (--i));
                    c++;
                }
                return;
            }
        }
        else {  // max 보다 낮을 때
            if (i > 0 && num[i] - '0' > num[i - 1] - '0') {  // 순서대로 진행이 안될 떄
                int ei = i;
                while (true) {
                    num.erase(num.begin() + (--ei));
                    c++;
                    if (c == k || num[ei] < num[ei - 1]) {
                        i = ei;
                        break;
                    }
                }
            }
            else {  // 순서대로 진행 될 때
                i++;
            }
        }
        if (c == k) {
            return;
        }
    }
    while (c != k) {
        num.pop_back();
        c++;
    }
}


*/