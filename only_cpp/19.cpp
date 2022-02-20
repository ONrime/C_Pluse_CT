#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*

H-Index

*/

bool compare(int a, int b) { // �������� ��
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), compare); // ���� ������������ �ϱ�

    vector<int>::iterator it;
    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] <= i) {   // �ο� Ƚ���� �������� �۰ų� ������ �� ���� ������ H-Index�̴�.
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