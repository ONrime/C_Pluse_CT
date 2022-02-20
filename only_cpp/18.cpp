#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*

모의고사

*/

int count_circle(vector<int> answers, vector<int>supo) {
    vector<int>::iterator it_ans;
    int i = 0;
    int all = 0;
    for (it_ans = answers.begin(); it_ans != answers.end(); it_ans++) {
        if (i == supo.size()) { i = 0; }
        if (*it_ans == supo[i]) {
            all++;
        }
        i++;
    }
    return all;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> supo1 = { 1, 2, 3, 4, 5 }, supo2 = { 2, 1, 2, 3, 2, 4, 2, 5 }
    , supo3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    vector<int> count;
    int max_count = 0;
    count.push_back(count_circle(answers, supo1));
    count.push_back(count_circle(answers, supo2));
    count.push_back(count_circle(answers, supo3));
    max_count = max(count[2], max(count[0], count[1]));

    for (int j = 0; j < 3; j++) {
        if (max_count == count[j]) { answer.push_back(j + 1); }
    }

    cout << "solution" << endl;
    vector<int>::iterator it0;
    cout << "count: ";
    for (it0 = count.begin(); it0 != count.end(); it0++) {
        cout << *it0 << " ";
    }
    cout << endl;

    vector<int>::iterator it;
    cout << "answer: ";
    for (it = answer.begin(); it != answer.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return answer;
}
vector<int> solution2(vector<int> answers) { // 나머지 방법을 이용하여 일정 구간을 반복 시켜 해결하였다.
    vector<int> answer;
    vector<int> supo1 = { 1, 2, 3, 4, 5 }, supo2 = { 2, 1, 2, 3, 2, 4, 2, 5 }
    , supo3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    vector<int> count = { 0, 0, 0 };
    int max_count = 0;
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == supo1[i % supo1.size()]) count[0]++;  // 0, 1, 2, 3, 4 를 반복
        if (answers[i] == supo2[i % supo2.size()]) count[1]++;  // 0, 1, 2, 3, 4, 5, 6, 7 를 반복
        if (answers[i] == supo3[i % supo3.size()]) count[2]++;  // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 를 반복
    }
    max_count = max(count[2], max(count[0], count[1]));

    for (int j = 0; j < 3; j++) {
        if (max_count == count[j]) { answer.push_back(j + 1); }
    }

    cout << "solution2" << endl;
    vector<int>::iterator it0;
    cout << "count: ";
    for (it0 = count.begin(); it0 != count.end(); it0++) {
        cout << *it0 << " ";
    }
    cout << endl;

    vector<int>::iterator it;
    cout << "answer: ";
    for (it = answer.begin(); it != answer.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return answer;
}

/*int main()
{
    solution({ 1,2,3,4,5 }); // 1
    solution2({ 1,2,3,4,5 }); // 1
    solution({ 1,3,2,4,2 }); // 1,2,3
    solution2({ 1,3,2,4,2 }); // 1,2,3
}*/
