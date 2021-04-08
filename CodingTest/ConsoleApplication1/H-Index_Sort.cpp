#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

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

/*

H-Index

���� ����
H-Index�� �������� ���꼺�� ������� ��Ÿ���� ��ǥ�Դϴ�. ��� �������� H-Index�� ��Ÿ���� ���� h�� ���Ϸ��� �մϴ�. ��Ű���1�� ������, H-Index�� ������ ���� ���մϴ�.

� �����ڰ� ��ǥ�� �� n�� ��, h�� �̻� �ο�� ���� h�� �̻��̰� ������ ���� h�� ���� �ο�Ǿ��ٸ� h�� �ִ��� �� �������� H-Index�Դϴ�.

� �����ڰ� ��ǥ�� ���� �ο� Ƚ���� ���� �迭 citations�� �Ű������� �־��� ��, �� �������� H-Index�� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
�����ڰ� ��ǥ�� ���� ���� 1�� �̻� 1,000�� �����Դϴ�.
���� �ο� Ƚ���� 0ȸ �̻� 10,000ȸ �����Դϴ�.
����� ��
citations	return
[3, 0, 6, 1, 5]	3
����� �� ����
�� �����ڰ� ��ǥ�� ���� ���� 5���̰�, ���� 3���� ���� 3ȸ �̻� �ο�Ǿ����ϴ�. �׸��� ������ 2���� ���� 3ȸ ���� �ο�Ǿ��� ������ �� �������� H-Index�� 3�Դϴ�.

*/