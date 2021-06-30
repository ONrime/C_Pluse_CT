#include <string>
#include <vector>
#include <iostream>

using namespace std;

void FindNetwork(bool check[], vector<vector<int>> computers, int next) {
    if (check[next] == true) return;
    check[next] = true;
    for (int i = 0; i < computers.size(); i++) {
        if (next != i && computers[next][i] == 1 && check[i] == false) {
            FindNetwork(check, computers, i);
        }
    }
}

int solution28(int n, vector<vector<int>> computers) {
    int answer = 0;
    bool check[200] = { false, };
    for (int i = 0; i < n; i++) {
        if (check[i] == false) {
            answer++;
            FindNetwork(check, computers, i);
        }
    }
    cout << "answer: " << answer << endl;

    return answer;
}

/*int main()
{
    //solution28(3, { { 1, 1, 0 }, {1, 1, 0}, {0, 0, 1} }); // 2
    //solution28(3, { { 1, 1, 0 }, {1, 1, 1}, {0, 1, 1} }); // 1
    //solution28(4, { { 1, 0, 0, 1 }, {0, 1, 1, 0}, {0, 1, 1, 0}, {1, 1, 0, 1} }); // 1
    //solution28(4, { { 1, 0, 0, 1 }, {0, 1, 1, 1}, {0, 1, 1, 0}, {1, 1, 0, 1} }); // 1
    solution28(1, { { 1 } }); // 1
    solution28(5, { { 1, 0, 0, 1, 0 }, {0, 1, 1, 0, 0}, {0, 1, 1, 0, 0}, {1, 0, 0, 1, 1}, {0, 0, 0, 1, 1} }); // 2
    //solution28(6, { { 1, 0, 1, 1, 0, 0 }, {0, 1, 0, 0, 1, 1}, {1, 0, 1, 1, 1, 1}, {1, 0, 1, 1, 1, 1}
    //    , {0, 1, 1, 1, 1, 1}, {0, 1, 1, 1, 1, 1} }); // 1
}*/

/*

��Ʈ��ũ

���� ����
��Ʈ��ũ�� ��ǻ�� ��ȣ ���� ������ ��ȯ�� �� �ֵ��� ����� ���¸� �ǹ��մϴ�. ���� ���, ��ǻ�� A�� ��ǻ�� B�� ���������� ����Ǿ��ְ�, ��ǻ�� B�� ��ǻ�� C�� ���������� ����Ǿ� ���� �� ��ǻ�� A�� ��ǻ�� C�� ���������� ����Ǿ� ������ ��ȯ�� �� �ֽ��ϴ�. ���� ��ǻ�� A, B, C�� ��� ���� ��Ʈ��ũ �� �ִٰ� �� �� �ֽ��ϴ�.

��ǻ���� ���� n, ���ῡ ���� ������ ��� 2���� �迭 computers�� �Ű������� �־��� ��, ��Ʈ��ũ�� ������ return �ϵ��� solution �Լ��� �ۼ��Ͻÿ�.

���ѻ���
��ǻ���� ���� n�� 1 �̻� 200 ������ �ڿ����Դϴ�.
�� ��ǻ�ʹ� 0���� n-1�� ������ ǥ���մϴ�.
i�� ��ǻ�Ϳ� j�� ��ǻ�Ͱ� ����Ǿ� ������ computers[i][j]�� 1�� ǥ���մϴ�.
computer[i][i]�� �׻� 1�Դϴ�.
����� ��
n	computers	return
3	[[1, 1, 0], [1, 1, 0], [0, 0, 1]]	2
3	[[1, 1, 0], [1, 1, 1], [0, 1, 1]]	1

*/