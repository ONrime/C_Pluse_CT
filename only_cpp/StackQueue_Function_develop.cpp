#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution10(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> pro_queue;
    queue<int> speeds_queue;

    vector<int>::iterator pro_it;
    vector<int>::iterator speeds_it = speeds.begin();
    for (pro_it = progresses.begin(); pro_it != progresses.end(); pro_it++) {
        pro_queue.push(*pro_it);
        speeds_queue.push(*speeds_it);
        speeds_it++;
    }
    float day = 0.0f;
    while (pro_queue.size() != 0) {
        int front = pro_queue.front();
        day += ceil((float)(100 - front) / (float)speeds_queue.front());
        int count = 1;
        pro_queue.pop();
        speeds_queue.pop();

        int pro_queue_size = pro_queue.size();
        for (int i = 0; i < pro_queue_size; i++) {
            int pro_f = pro_queue.front();
            int speeds_f = speeds_queue.front();
            if ((day * speeds_f) + pro_f >= 100) {
                count++;
                pro_queue.pop();
                speeds_queue.pop();
            }
            else {
                break;
            }
        }
        answer.push_back(count);
    }

    cout << "answer: ";
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << "\n";

    return answer;
}

/*int main()
{
    solution10({ 93, 30, 55 }, { 1, 30, 5 }); // 2 1
    solution10({ 95, 90, 99, 99, 80, 99 }, { 1, 1, 1, 1, 1, 1 }); // 1 3 2
    solution10({ 93 }, { 1 }); // 1
}*/

/*

��ɰ���

���� ����
���α׷��ӽ� �������� ��� ���� �۾��� ���� ���Դϴ�. �� ����� ������ 100%�� �� ���񽺿� �ݿ��� �� �ֽ��ϴ�.

��, �� ����� ���߼ӵ��� ��� �ٸ��� ������ �ڿ� �ִ� ����� �տ� �ִ� ��ɺ��� ���� ���ߵ� �� �ְ�, �̶� �ڿ� �ִ� ����� �տ� �ִ� ����� ������ �� �Բ� �����˴ϴ�.

���� �����Ǿ�� �ϴ� ������� �۾��� ������ ���� ���� �迭 progresses�� �� �۾��� ���� �ӵ��� ���� ���� �迭 speeds�� �־��� �� �� �������� �� ���� ����� �����Ǵ����� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

���� ����
�۾��� ����(progresses, speeds�迭�� ����)�� 100�� �����Դϴ�.
�۾� ������ 100 �̸��� �ڿ����Դϴ�.
�۾� �ӵ��� 100 ������ �ڿ����Դϴ�.
������ �Ϸ翡 �� ���� �� �� ������, �Ϸ��� ���� �̷�����ٰ� �����մϴ�. ���� ��� �������� 95%�� �۾��� ���� �ӵ��� �Ϸ翡 4%��� ������ 2�� �ڿ� �̷�����ϴ�.
����� ��
progresses	speeds	return
[93, 30, 55]	[1, 30, 5]	[2, 1]
[95, 90, 99, 99, 80, 99]	[1, 1, 1, 1, 1, 1]	[1, 3, 2]
����� �� ����
����� �� #1
ù ��° ����� 93% �Ϸ�Ǿ� �ְ� �Ϸ翡 1%�� �۾��� �����ϹǷ� 7�ϰ� �۾� �� ������ �����մϴ�.
�� ��° ����� 30%�� �Ϸ�Ǿ� �ְ� �Ϸ翡 30%�� �۾��� �����ϹǷ� 3�ϰ� �۾� �� ������ �����մϴ�. ������ ���� ù ��° ����� ���� �ϼ��� ���°� �ƴϱ� ������ ù ��° ����� �����Ǵ� 7��° �����˴ϴ�.
�� ��° ����� 55%�� �Ϸ�Ǿ� �ְ� �Ϸ翡 5%�� �۾��� �����ϹǷ� 9�ϰ� �۾� �� ������ �����մϴ�.

���� 7��°�� 2���� ���, 9��°�� 1���� ����� �����˴ϴ�.

����� �� #2
��� ����� �Ϸ翡 1%�� �۾��� �����ϹǷ�, �۾��� ��������� ���� �ϼ��� ���� 5��, 10��, 1��, 1��, 20��, 1���Դϴ�. � ����� ���� �ϼ��Ǿ����� �տ� �ִ� ��� ����� �ϼ����� ������ ������ �Ұ����մϴ�.

���� 5��°�� 1���� ���, 10��°�� 3���� ���, 20��°�� 2���� ����� �����˴ϴ�.

*/