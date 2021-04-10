#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

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

/*

모의고사
문제 설명
수포자는 수학을 포기한 사람의 준말입니다. 수포자 삼인방은 모의고사에 수학 문제를 전부 찍으려 합니다. 수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다.

1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때, 가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한 조건
시험은 최대 10,000 문제로 구성되어있습니다.
문제의 정답은 1, 2, 3, 4, 5중 하나입니다.
가장 높은 점수를 받은 사람이 여럿일 경우, return하는 값을 오름차순 정렬해주세요.
입출력 예
answers	return
[1,2,3,4,5]	[1]
[1,3,2,4,2]	[1,2,3]
입출력 예 설명
입출력 예 #1

수포자 1은 모든 문제를 맞혔습니다.
수포자 2는 모든 문제를 틀렸습니다.
수포자 3은 모든 문제를 틀렸습니다.
따라서 가장 문제를 많이 맞힌 사람은 수포자 1입니다.

입출력 예 #2

모든 사람이 2문제씩을 맞췄습니다.

*/