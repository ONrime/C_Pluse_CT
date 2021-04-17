#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include<string>

using namespace std;

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
char* solution(const char* number, int k) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    char* answer = (char*)malloc(1);
    string a = number;
    vector<int> temp;
    int n = a.size() - k;
    for (int i = 0; i < n; i++) {
        temp.push_back(1);
    }
    for (int i = 0; i < a.size() - n; i++) {
        temp.push_back(0);
    }
    int max = 0;
    do {
        string num;
        for (int i = 0; i < a.size(); i++) {
            if (temp[i] == 1) {
                num.push_back(a[i]);
            }
        }
        int num_ = stoi(num);
        if (max < num_) {
            max = num_;
        }
    } while (prev_permutation(temp.begin(), temp.end()));
    string b = to_string(max);
    //answer = b;
    cout << "answer: " << b << endl;
    //cout << "answer: " << a << endl;
    return answer;
}

/*int main()
{
    solution("1924", 2); // 94
    solution("1231234", 3); // 3234
    solution("4177252841", 4); // 775841
}*/

/*

ū �� �����

���� ����
� ���ڿ��� k���� ���� �������� �� ���� �� �ִ� ���� ū ���ڸ� ���Ϸ� �մϴ�.

���� ���, ���� 1924���� �� �� ���� �����ϸ� [19, 12, 14, 92, 94, 24] �� ���� �� �ֽ��ϴ�. �� �� ���� ū ���ڴ� 94 �Դϴ�.

���ڿ� �������� ���� number�� ������ ���� ���� k�� solution �Լ��� �Ű������� �־����ϴ�. number���� k ���� ���� �������� �� ���� �� �ִ� �� �� ���� ū ���ڸ� ���ڿ� ���·� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

���� ����
number�� 1�ڸ� �̻�, 1,000,000�ڸ� ������ �����Դϴ�.
k�� 1 �̻� number�� �ڸ��� �̸��� �ڿ����Դϴ�.
����� ��
number	k	return
"1924"	2	"94"
"1231234"	3	"3234"
"4177252841"	4	"775841"

*/