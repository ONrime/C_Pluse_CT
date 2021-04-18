#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution12(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> scov;

    vector<int>::iterator it_scoville;
    for (it_scoville = scoville.begin(); it_scoville != scoville.end(); it_scoville++) {
        scov.push(*it_scoville);
    }

    while (true) {
        if (scov.top() < K) {
            int top_1 = scov.top();
            scov.pop();
            int top_2 = scov.top();
            scov.pop();

            int new_scov = top_1 + (top_2 * 2);
            scov.push(new_scov);
            answer++;
        }
        else {
            break;
        }
        if (scov.size() < 2 && scov.top() < K) {
            answer = -1;
            break;
        }
    }

    return answer;
}

/*int main()
{
    cout << "answer: " << solution12({ 1, 2, 3, 9, 10, 12 }, 7) << "\n"; // 2
    cout << "answer: " << solution12({ 1, 1, 1 }, 4) << "\n"; // 2
    cout << "answer: " << solution12({ 10, 10, 10, 10, 10 }, 100) << "\n"; // 4
    cout << "answer: " << solution12({ 1, 2, 3, 9, 10, 12 }, 7) << "\n"; // 2
    cout << "answer: " << solution12({ 0, 0, 3, 9, 10, 12 }, 7000) << "\n"; // -1
    cout << "answer: " << solution12({ 0, 0 }, 0) << "\n"; // 0
    cout << "answer: " << solution12({ 0, 0 }, 1) << "\n"; // -1
    cout << "answer: " << solution12({ 1, 0 }, 1) << "\n"; // 1
}*/

/*

�� �ʰ�

���� ����
�ſ� ���� �����ϴ� Leo�� ��� ������ ���ں� ������ K �̻����� ����� �ͽ��ϴ�. ��� ������ ���ں� ������ K �̻����� ����� ���� Leo�� ���ں� ������ ���� ���� �� ���� ������ �Ʒ��� ���� Ư���� ������� ���� ���ο� ������ ����ϴ�.

���� ������ ���ں� ���� = ���� ���� ���� ������ ���ں� ���� + (�� ��°�� ���� ���� ������ ���ں� ���� * 2)
Leo�� ��� ������ ���ں� ������ K �̻��� �� ������ �ݺ��Ͽ� �����ϴ�.
Leo�� ���� ������ ���ں� ������ ���� �迭 scoville�� ���ϴ� ���ں� ���� K�� �־��� ��, ��� ������ ���ں� ������ K �̻����� ����� ���� ����� �ϴ� �ּ� Ƚ���� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���� ����
scoville�� ���̴� 2 �̻� 1,000,000 �����Դϴ�.
K�� 0 �̻� 1,000,000,000 �����Դϴ�.
scoville�� ���Ҵ� ���� 0 �̻� 1,000,000 �����Դϴ�.
��� ������ ���ں� ������ K �̻����� ���� �� ���� ��쿡�� -1�� return �մϴ�.
����� ��
scoville	K	return
[1, 2, 3, 9, 10, 12]	7	2
����� �� ����
���ں� ������ 1�� ���İ� 2�� ������ ������ ������ ���ں� ������ �Ʒ��� ���� �˴ϴ�.
���ο� ������ ���ں� ���� = 1 + (2 * 2) = 5
���� ������ ���ں� ���� = [5, 3, 9, 10, 12]

���ں� ������ 3�� ���İ� 5�� ������ ������ ������ ���ں� ������ �Ʒ��� ���� �˴ϴ�.
���ο� ������ ���ں� ���� = 3 + (5 * 2) = 13
���� ������ ���ں� ���� = [13, 9, 10, 12]

��� ������ ���ں� ������ 7 �̻��� �Ǿ��� �̶� ���� Ƚ���� 2ȸ�Դϴ�.

*/