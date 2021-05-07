#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct greater_jobs {
    bool operator()(vector<int>& a, vector<int>& b) {
        if (*(a.begin() + 1) == *(b.begin() + 1)) {
            return *(a.begin()) > * (b.begin());
        }
        return *(a.begin() + 1) > * (b.begin() + 1);
    }
};

struct less_jobs {
    bool operator()(vector<int>& a, vector<int>& b) {
        if (*(a.begin() + 1) == *(b.begin() + 1)) {
            return *(a.begin()) > * (b.begin());
        }
        return *(a.begin() + 1) > * (b.begin() + 1);
    }
};

int solution13(vector<vector<int>> jobs) {
    int answer = 0;
    int length = 0;
    int sum = 0;
    int min = 0;
    priority_queue<vector<int>, vector<vector<int>>, less_jobs> jobs_queue;
    vector<vector<int>>::iterator it_job = jobs.begin();

    sort(jobs.begin(), jobs.end());
    int i = 0;
    int count = 0;
    while (true) {
        if (i < jobs.size() && (*((it_job + i)->begin()) <= length || jobs_queue.empty())) {
            jobs_queue.push(*(it_job + i));
            i++;
            continue;
        }
        else {
            if (*(jobs_queue.top().begin()) < length) {
                length += *(jobs_queue.top().begin() + 1);
            }
            else {
                length = *(jobs_queue.top().begin()) + *(jobs_queue.top().begin() + 1);
            }
            min = *(jobs_queue.top().begin());
            sum += length - min;
            jobs_queue.pop();
            count++;
        }
        if (count >= jobs.size()) {
            break;
        }
    }
    /*cout << "ceil: " << ceil(((float)sum / (float)jobs.size())) << "\n";
    cout << "sum: " << (float)(sum) << "\n";*/
    answer = (sum / jobs.size());

    return answer;
}

int main()
{
    cout << "answer: " << solution13({ { 0, 3 }, { 1, 9 }, { 2, 6 } }) << "\n"; //9
    cout << "answer: " << solution13({ { 0, 10 }, { 2, 10 }, { 9, 10 }, { 15, 2 } }) << "\n"; //14
    cout << "answer: " << solution13({ { 0, 1 } }) << "\n"; //1
    cout << "answer: " << solution13({ { 1000, 1000 } }) << "\n"; //1000
    cout << "answer: " << solution13({ {0, 1} ,{0, 1}, {0, 1} }) << "\n"; //2
    cout << "answer: " << solution13({ {0, 1} ,{0, 1}, {0, 1}, {0, 1} }) << "\n"; //2
    cout << "answer: " << solution13({ {0, 1} ,{1000, 1000}}) << "\n"; //500
    cout << "answer: " << solution13({ {100, 100} ,{1000, 1000}}) << "\n"; //550
    cout << "answer: " << solution13({ {10, 10} ,{30, 10}, {50, 2}, {51, 2} }) << "\n"; //6
    cout << "answer: " << solution13({ {0, 3} ,{1, 9}, {2, 6}, {30, 3} }) << "\n"; //7
}

/*

��ũ ��Ʈ�ѷ�

���� ����
�ϵ��ũ�� �� ���� �ϳ��� �۾��� ������ �� �ֽ��ϴ�. ��ũ ��Ʈ�ѷ��� �����ϴ� ����� ���� ������ �ֽ��ϴ�. ���� �Ϲ����� ����� ��û�� ���� ������� ó���ϴ� ���Դϴ�.

�������

- 0ms ������ 3ms�� �ҿ�Ǵ� A�۾� ��û
- 1ms ������ 9ms�� �ҿ�Ǵ� B�۾� ��û
- 2ms ������ 6ms�� �ҿ�Ǵ� C�۾� ��û
�� ���� ��û�� ���Խ��ϴ�. �̸� �׸����� ǥ���ϸ� �Ʒ��� �����ϴ�.

�� ���� �ϳ��� ��û���� ������ �� �ֱ� ������ ������ �۾��� ��û���� ������� ó���ϸ� ������ ���� ó�� �˴ϴ�.

- A: 3ms ������ �۾� �Ϸ� (��û���� ������� : 3ms)
- B: 1ms���� ����ϴٰ�, 3ms ������ �۾��� �����ؼ� 12ms ������ �۾� �Ϸ�(��û���� ������� : 11ms)
- C: 2ms���� ����ϴٰ�, 12ms ������ �۾��� �����ؼ� 18ms ������ �۾� �Ϸ�(��û���� ������� : 16ms)
�� �� �� �۾��� ��û���� ������� �ɸ� �ð��� ����� 10ms(= (3 + 11 + 16) / 3)�� �˴ϴ�.

������ A �� C �� B ������� ó���ϸ�

- A: 3ms ������ �۾� �Ϸ�(��û���� ������� : 3ms)
- C: 2ms���� ����ϴٰ�, 3ms ������ �۾��� �����ؼ� 9ms ������ �۾� �Ϸ�(��û���� ������� : 7ms)
- B: 1ms���� ����ϴٰ�, 9ms ������ �۾��� �����ؼ� 18ms ������ �۾� �Ϸ�(��û���� ������� : 17ms)
�̷��� A �� C �� B�� ������ ó���ϸ� �� �۾��� ��û���� ������� �ɸ� �ð��� ����� 9ms(= (3 + 7 + 17) / 3)�� �˴ϴ�.

�� �۾��� ���� [�۾��� ��û�Ǵ� ����, �۾��� �ҿ�ð�]�� ���� 2���� �迭 jobs�� �Ű������� �־��� ��, �۾��� ��û���� ������� �ɸ� �ð��� ����� ���� ���̴� ������� ó���ϸ� ����� �󸶰� �Ǵ��� return �ϵ��� solution �Լ��� �ۼ����ּ���. (��, �Ҽ��� ������ ���� �����ϴ�)

���� ����
jobs�� ���̴� 1 �̻� 500 �����Դϴ�.
jobs�� �� ���� �ϳ��� �۾��� ���� [�۾��� ��û�Ǵ� ����, �۾��� �ҿ�ð�] �Դϴ�.
�� �۾��� ���� �۾��� ��û�Ǵ� �ð��� 0 �̻� 1,000 �����Դϴ�.
�� �۾��� ���� �۾��� �ҿ�ð��� 1 �̻� 1,000 �����Դϴ�.
�ϵ��ũ�� �۾��� �����ϰ� ���� ���� ������ ���� ��û�� ���� �۾����� ó���մϴ�.
����� ��
jobs	return
[[0, 3], [1, 9], [2, 6]]	9
����� �� ����
������ �־��� ���� �����ϴ�.

0ms ������ 3ms �ɸ��� �۾� ��û�� ���ɴϴ�.
1ms ������ 9ms �ɸ��� �۾� ��û�� ���ɴϴ�.
2ms ������ 6ms �ɸ��� �۾� ��û�� ���ɴϴ�.

*/