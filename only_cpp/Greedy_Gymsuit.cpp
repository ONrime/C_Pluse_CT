#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool gym_compare(int a, int b) {
    return a > b;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    vector <int> give;

    sort(lost.begin(), lost.end(), gym_compare);
    sort(reserve.begin(), reserve.end());

    give.push_back(0);
    for (auto it = reserve.begin(); it != reserve.end(); it++) {
        if (lost.empty()) {
            break;
        }
        if (give.back() == lost.back()) { lost.pop_back(); }
        if (give.back() == (*it)) { continue; }

        if ((*it) == lost.back() - 1 || (*it) == lost.back() + 1 || (*it) == lost.back()) {
            int x = 0;
            (*it) > lost.back() ? x = (*it) : x = lost.back();
            give.push_back(x);
            lost.pop_back();
            answer++;
        }
        else if ((*it) > lost.back()) {
            lost.pop_back();
            it--;
        }
    }

    
    return answer;
}

/*int main()
{
    //cout << "answer: " << solution(5, { 2, 4 }, { 1, 3, 5 }) << endl; // 5
    //cout << "answer: " << solution(8, { 2, 40, 50 }, { 1, 3, 5, 49 }) << endl; // 7
    //cout << "answer: " << solution(8, { 2, 40, 49 }, { 1, 3, 5, 49 }) << endl; // 7
    cout << "answer: " << solution(4, { 3, 1, 2 }, { 2, 4, 3 }) << endl; // 3
    //cout << "answer: " << solution(2, { 1 }, { 4 }) << endl; // 1
    //cout << "answer: " << solution(5, { 2, 4 }, { 3 }) << endl; // 4
    //cout << "answer: " << solution(3, { 3 }, { 1 }) <<endl; // 2
    //cout << "answer: " << solution(4, { 3, 1 }, { 2, 4 }) <<endl; // 4
    //cout << "answer: " << solution(2, { 1 }, { 2 }) <<endl; // 2
    cout << "answer: " << solution(5, { 2, 3, 4 }, { 1, 2, 3 }) <<endl; // 4
    cout << "answer: " << solution(5, { 1, 2, 3 }, { 2, 3, 4 }) <<endl; // 4
}*/

/*

ü����
���� ����
���ɽð��� ������ ���, �Ϻ� �л��� ü������ �������߽��ϴ�. ������ ���� ü������ �ִ� �л��� �̵鿡�� ü������ �����ַ� �մϴ�. �л����� ��ȣ�� ü�� ������ �Ű��� �־�, �ٷ� �չ�ȣ�� �л��̳� �ٷ� �޹�ȣ�� �л����Ը� ü������ ������ �� �ֽ��ϴ�. ���� ���, 4�� �л��� 3�� �л��̳� 5�� �л����Ը� ü������ ������ �� �ֽ��ϴ�. ü������ ������ ������ ���� �� ���� ������ ü������ ������ ���� �ִ��� ���� �л��� ü�������� ���� �մϴ�.

��ü �л��� �� n, ü������ �������� �л����� ��ȣ�� ��� �迭 lost, ������ ü������ ������ �л����� ��ȣ�� ��� �迭 reserve�� �Ű������� �־��� ��, ü�������� ���� �� �ִ� �л��� �ִ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
��ü �л��� ���� 2�� �̻� 30�� �����Դϴ�.
ü������ �������� �л��� ���� 1�� �̻� n�� �����̰� �ߺ��Ǵ� ��ȣ�� �����ϴ�.
������ ü������ ������ �л��� ���� 1�� �̻� n�� �����̰� �ߺ��Ǵ� ��ȣ�� �����ϴ�.
���� ü������ �ִ� �л��� �ٸ� �л����� ü������ ������ �� �ֽ��ϴ�.
���� ü������ ������ �л��� ü������ ���������� �� �ֽ��ϴ�. �̶� �� �л��� ü������ �ϳ��� �������ߴٰ� �����ϸ�, ���� ü������ �ϳ��̱⿡ �ٸ� �л����Դ� ü������ ������ �� �����ϴ�.
����� ��
n	lost	reserve	return
5	[2, 4]	[1, 3, 5]	5
5	[2, 4]	[3]	4
3	[3]	[1]	2
����� �� ����
���� #1
1�� �л��� 2�� �л����� ü������ �����ְ�, 3�� �л��̳� 5�� �л��� 4�� �л����� ü������ �����ָ� �л� 5���� ü�������� ���� �� �ֽ��ϴ�.

���� #2
3�� �л��� 2�� �л��̳� 4�� �л����� ü������ �����ָ� �л� 4���� ü�������� ���� �� �ֽ��ϴ�.

*/