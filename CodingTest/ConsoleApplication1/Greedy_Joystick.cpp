#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;

int solution(string name) {
    int answer = 0;
    //cout << "name: " << (int)name[0] - 65;
    string::iterator it;
    /* int count = 0;
    for (int i = 0; i < name.size(); i++) {
        int num = (int)name[i] - 65;
        if (i > 0 && num == 0 && count == i - 1) {
            answer -= 1;
            count++;
            continue;
        }
        if (num < 14) {
            answer += num;
        }
        else {
            num = abs(26 - num);
            answer += num;
        }

        answer += 1;
    }*/
    /*int count = 0;
    int count2 = -1;
    int max = 0;
    bool zero_check = true;
    vector<int>check(2);
    answer = -1;
    for (int i = 0; i < name.size(); i++) {
        int num = (int)name[i] - 65;
        //answer += 1;
        count2 += 1;
        if (i > 0 && num == 0) {//
            if (count == 0) { check[0] = count2; }
            count++;
            continue;
        }
        if (num < 14) {
            answer += num;
        }
        else {
            num = abs(26 - num);
            answer += num;
        }
        if (count > max) {
            max = count;
        }
        count = 0;

       

        //answer += 1;
    }
    check[1] = name.size() - (check[0] + max);
    if (check[0] > check[1]) {
        answer = answer + (check[0] * 2) + 1 + check[1];
    }
    else {
        answer = answer + 1 + (check[1] * 2) + 1 + check[0];
    }*/
    //cout << "answer: " << j << endl; // 23
    cout << "1: " << name[0]<< endl; // 23
    int i = 0;
    string temp(name.size(), 'A');
    while (true) {
        temp[i] = name[i];
        int num = (int)name[i] - 65;
        if (num > 13) { num = abs(26 - num); }
        answer += num;
        if (temp == name) { break; }

        for (int j = 1; j < name.size(); j++) {
            if (name[(i + j) % name.size()] != temp[(i + j) % name.size()]) {
                i = (i + j) % name.size();
                answer += j;
                break;
            }
            else if (name[(i + name.size() - j) % name.size()] != temp[(i + name.size() - j) % name.size()]) {
                i = (i + name.size() - j) % name.size();
                answer += j;
                break;
            }
        }
    }
    return answer;
}

int main()
{
    cout << "answer: " << solution("JAZ") << endl; // 11
    cout << "answer: " << solution("JEROEN") << endl; // 56
    cout << "answer: " << solution("JAN") << endl; // 23
    cout << "answer: " << solution("ABAAAAABAB") << endl; // 8
    //cout << "answer: " << solution("ABABAAAAAB") << endl; // 8
}

/*

���̽�ƽ

���� ����
���̽�ƽ���� ���ĺ� �̸��� �ϼ��ϼ���. �� ó���� A�θ� �̷���� �ֽ��ϴ�.
ex) �ϼ��ؾ� �ϴ� �̸��� �� ���ڸ� AAA, �� ���ڸ� AAAA

���̽�ƽ�� �� �������� �����̸� �Ʒ��� �����ϴ�.

�� - ���� ���ĺ�
�� - ���� ���ĺ� (A���� �Ʒ������� �̵��ϸ� Z��)
�� - Ŀ���� �������� �̵� (ù ��° ��ġ���� �������� �̵��ϸ� ������ ���ڿ� Ŀ��)
�� - Ŀ���� ���������� �̵�
���� ��� �Ʒ��� ������� "JAZ"�� ���� �� �ֽ��ϴ�.

- ù ��° ��ġ���� ���̽�ƽ�� ���� 9�� �����Ͽ� J�� �ϼ��մϴ�.
- ���̽�ƽ�� �������� 1�� �����Ͽ� Ŀ���� ������ ���� ��ġ�� �̵���ŵ�ϴ�.
- ������ ��ġ���� ���̽�ƽ�� �Ʒ��� 1�� �����Ͽ� Z�� �ϼ��մϴ�.
���� 11�� �̵����� "JAZ"�� ���� �� �ְ�, �̶��� �ּ� �̵��Դϴ�.
������� �ϴ� �̸� name�� �Ű������� �־��� ��, �̸��� ���� ���̽�ƽ ���� Ƚ���� �ּڰ��� return �ϵ��� solution �Լ��� ���弼��.

���� ����
name�� ���ĺ� �빮�ڷθ� �̷���� �ֽ��ϴ�.
name�� ���̴� 1 �̻� 20 �����Դϴ�.
����� ��
name	return
"JEROEN"	56
"JAN"	23

*/