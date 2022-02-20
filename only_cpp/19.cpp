#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*

H-Index

*/

bool compare(int a, int b) { // 내림차순 비교
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), compare); // 정렬 내림차순으로 하기

    vector<int>::iterator it;
    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] <= i) {   // 인용 횟수가 순서보다 작거나 같으면 그 때의 순서가 H-Index이다.
            answer = i;
            return answer;
        }
    }
    answer = citations.size();
    return answer;
}

/*int main(){
    cout << "answer: " << solution({ 3, 0, 6, 1, 5 }) << endl; // [3, 0, 6, 1, 5]	3
    cout << "answer: " << solution({ 10, 11, 12, 13 }) << endl; // [10, 11, 12, 13]  4
}*/