#include <iostream>

using namespace std;

long long solution21(int w, int h) {
    long long answer = 1;

    int gong = 1;
    long long ww = w;
    long long hh = h;
    while (true) {
        if (w % 3 == 0 && h % 3 == 0) {
            w /= 3;
            h /= 3;
            gong = gong * 3;
        }
        else if (w % 2 == 0 && h % 2 == 0) {
            w /= 2;
            h /= 2;
            gong = gong * 2;
        }
        else {
            break;
        }
    }
    answer = ww * hh - ((ww + hh) - (long long)gong);
    return answer;
}

long long solution22(int w, int h) {
    long long answer = 1;

    int gong = 0;
    long long sum = (long long)w + (long long)h;
    long long multi = (long long)w * (long long)h;
    int temp = 0;

    while (h != 0) {
        temp = w % h;
        w = h;
        h = temp;
    }
    gong = w;

    answer = multi - (sum - gong);
    return answer;
}

/*int main()
{
	cout << "answer: " << solution22(8, 12) << "\n"; // 80
	cout << "answer: " << solution22(3, 4) << "\n"; // 6
}*/
/*

������ �簢��

���� ����
���� ���̰� Wcm, ���� ���̰� Hcm�� ���簢�� ���̰� �ֽ��ϴ�. ���̿��� ����, ���� ����� �����ϰ� ���� ���·� ���� �׾��� ������, ��� ����ĭ�� 1cm x 1cm ũ���Դϴ�. �� ���̸� ���� ���� ���� 1cm �� 1cm�� ���簢������ �߶� ����� �����̾��µ�, �������� �� ���̸� �밢�� ������ 2���� �մ� �������� �߶� ���ҽ��ϴ�. �׷��Ƿ� ���� ���簢�� ���̴� ũ�Ⱑ ���� �����ﰢ�� 2���� �������� �����Դϴ�. ���ο� ���̸� ���� �� ���� �����̱� ������, �� ���̿��� ���� ������ ����, ���� ����� �����ϰ� 1cm �� 1cm�� �߶� ����� �� �ִ� ��ŭ�� ����ϱ�� �Ͽ����ϴ�.
������ ���� W�� ������ ���� H�� �־��� ��, ����� �� �ִ� ���簢���� ������ ���ϴ� solution �Լ��� �ϼ��� �ּ���.

���ѻ���
W, H : 1�� ������ �ڿ���
����� ��
W	H	result
8	12	80
����� �� ����
����� �� #1
���ΰ� 8, ���ΰ� 12�� ���簢���� �밢�� �������� �ڸ��� �� 16�� ���簢���� ����� �� ���� �˴ϴ�. ���� ���簢�������� 96���� ���簢���� ���� �� �־����Ƿ�, 96 - 16 = 80 �� ��ȯ�մϴ�.



*/