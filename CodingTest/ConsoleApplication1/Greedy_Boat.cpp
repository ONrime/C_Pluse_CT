#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());

    int i = 0;
    while (people.size()>i) {
        /*if (people.end() == people.begin() + i) {
            break;
        }*/
        if (limit < (people[i] + people.back())) {
            people.pop_back();
            answer++;
        }
        else {
            people.pop_back();
            i++;
            answer++;
        }
    }


    return answer;
}

/*int main()
{
    cout << "answer: " << solution({ 70, 50, 80, 50 }, 100) << "\n"; // 3
    cout << "answer: " << solution({ 70, 50, 80, 50, 50 }, 100) << "\n"; // 4
    cout << "answer: " << solution({ 70, 80, 50 }, 100) << "\n"; // 3
    cout << "answer: " << solution({ 40, 40, 80 }, 160) << "\n"; // 2
}*/

/*

����Ʈ

���� ����
���ε��� ���� ������� ����Ʈ�� �̿��Ͽ� �����Ϸ��� �մϴ�. ����Ʈ�� �۾Ƽ� �� ���� �ִ� 2�� �ۿ� Ż �� ����, ���� ���ѵ� �ֽ��ϴ�.

���� ���, ������� �����԰� [70kg, 50kg, 80kg, 50kg]�̰� ����Ʈ�� ���� ������ 100kg�̶�� 2��° ����� 4��° ����� ���� Ż �� ������ 1��° ����� 3��° ����� ������ ���� 150kg�̹Ƿ� ����Ʈ�� ���� ������ �ʰ��Ͽ� ���� Ż �� �����ϴ�.

����Ʈ�� �ִ��� ���� ����Ͽ� ��� ����� �����Ϸ��� �մϴ�.

������� �����Ը� ���� �迭 people�� ����Ʈ�� ���� ���� limit�� �Ű������� �־��� ��, ��� ����� �����ϱ� ���� �ʿ��� ����Ʈ ������ �ּڰ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
���ε��� ���� ����� 1�� �̻� 50,000�� �����Դϴ�.
�� ����� �����Դ� 40kg �̻� 240kg �����Դϴ�.
����Ʈ�� ���� ������ 40kg �̻� 240kg �����Դϴ�.
����Ʈ�� ���� ������ �׻� ������� ������ �� �ִ񰪺��� ũ�� �־����Ƿ� ������� ������ �� ���� ���� �����ϴ�.
����� ��
people	limit	return
[70, 50, 80, 50]	100	3
[70, 80, 50]	100	3

*/