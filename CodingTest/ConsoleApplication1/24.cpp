#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution25(int n) {
    string answer = "";
    while (n > 0) {
        int pushNum = n % 3; // �� �ڸ�
        if (pushNum == 0) pushNum = 4;
        answer = to_string(pushNum) + answer;
        n /= 3; // ����
        if (pushNum == 4) n--;
    }
    cout << "answer: " << answer << endl;

    return answer;
}

/*int main()
{
    solution25(39);
    solution25(10);
    solution25(11);
    solution25(12);
    solution25(500000000);
}*/

/*

124 ������ ����

���� ����
124 ���� �ֽ��ϴ�. 124 ���󿡼��� 10������ �ƴ� ������ ���� �ڽŵ鸸�� ��Ģ���� ���� ǥ���մϴ�.

124 ���󿡴� �ڿ����� �����մϴ�.
124 ���󿡴� ��� ���� ǥ���� �� 1, 2, 4�� ����մϴ�.
���� �� 124 ���󿡼� ����ϴ� ���ڴ� ������ ���� ��ȯ�˴ϴ�.

10����	124 ����	10����	124 ����
1	1	6	14
2	2	7	21
3	4	8	22
4	11	9	24
5	12	10	41
�ڿ��� n�� �Ű������� �־��� ��, n�� 124 ���󿡼� ����ϴ� ���ڷ� �ٲ� ���� return �ϵ��� solution �Լ��� �ϼ��� �ּ���.

���ѻ���
n�� 500,000,000������ �ڿ��� �Դϴ�.
����� ��
n	result
1	1
2	2
3	4
4	11

*/