#include <string>
#include <vector>
#include <iostream>

using namespace std;



int solution26(string s) {
    int answer = 0;
    string temp;
    string a = s;
    int count = 1;
    int start = 0;
    int less = 100000000;
   // cout << "check: " << (s.size() / 2)+1 << endl;
    for (int i = 1; i < (s.size() / 2) + 1; i++) {
        for (int j = 0; j < s.size() + 1; j += i) {
            if (temp.empty() == true) {
                count = 1;
                start = j;
                temp = s.substr(j, i);
            }
            else {
                if (temp == s.substr(j, i)) {count++;}
                else {
                    if (count != 1) {
                       s.replace(start, (count - 1) * i, to_string(count));
                       j = j - (count*i)+i;
                    }
                    else {j = j - i;}
                    //s.replace(start, (count - 1) * i, to_string(count));
                    //j = j - (count * i) + 1;
                    temp.clear();
                }
            }
        }
        //if (less > s.size()) less = strlen(s.c_str());
        if (less > s.size()) less = s.length();
        cout << "answerd: " << s << endl;
        s = a;
        temp.clear(); 
    }
    if (less == 100000000) less = s.length();
    cout << "answer: " << less << endl;
    return answer;
}
/*int main()
{
    solution26("xxxxxxxxxxyyy"); // 5
    solution26("abcdefghiuop"); // 12
    //solution26("aa  b"); // 5
    //solution26("aaaaaaaaaab"); // 4
    solution26("ababcdcdababcdcd"); // 9
    //solution26("abcdabcd"); // 5
   // solution26("a"); // 1
    solution26("aaaabbbacccccc"); // 7
    solution26("abcabcabcabcdededededede"); // 14
    solution26("abcabcdede"); // 8
    solution26("abababac"); // 7
    solution26("ababacacdd"); // 8
    solution26("ababcdcdababcdcd"); // 9
    //solution26("xababcdcdababcdcd"); // 17
   // solution26("acacacbacacac"); // 9 3acba2cac
   // solution26("acacacacacacbacacacacacac"); // 9 6acba5cac
    //solution26("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"); // 4 100a
    //solution26("zxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"); // 5 
    //solution26("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxz"); // 5 
    solution26("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"); // 5 
}*/
/*

���ڿ� ����

���� ����
������ ó�� �������� �ǰ� ���� "����ġ"�� ���ڿ��� �����ϴ� ����� ���� ���θ� �ϰ� �ֽ��ϴ�. �ֱٿ� �뷮�� ������ ó���� ���� ������ ��ս� ���� ����� ���� ���θ� �ϰ� �ִµ�, ���ڿ����� ���� ���� �����ؼ� ��Ÿ���� ���� �� ������ ������ �ݺ��Ǵ� ������ ǥ���Ͽ� �� ª�� ���ڿ��� �ٿ��� ǥ���ϴ� �˰����� �����ϰ� �ֽ��ϴ�.
������ ���� "aabbaccc"�� ��� "2a2ba3c"(���ڰ� �ݺ����� �ʾ� �ѹ��� ��Ÿ�� ��� 1�� ������)�� ���� ǥ���� �� �ִµ�, �̷��� ����� �ݺ��Ǵ� ���ڰ� ���� ��� ������� ���ٴ� ������ �ֽ��ϴ�. ���� ���, "abcabcdede"�� ���� ���ڿ��� ���� ������� �ʽ��ϴ�. "����ġ"�� �̷��� ������ �ذ��ϱ� ���� ���ڿ��� 1�� �̻��� ������ �߶� �����Ͽ� �� ª�� ���ڿ��� ǥ���� �� �ִ��� ����� ã�ƺ����� �մϴ�.

���� ���, "ababcdcdababcdcd"�� ��� ���ڸ� 1�� ������ �ڸ��� ���� ������� ������, 2�� ������ �߶� �����Ѵٸ� "2ab2cd2ab2cd"�� ǥ���� �� �ֽ��ϴ�. �ٸ� ������� 8�� ������ �߶� �����Ѵٸ� "2ababcdcd"�� ǥ���� �� ������, �̶��� ���� ª�� �����Ͽ� ǥ���� �� �ִ� ����Դϴ�.

�ٸ� ����, "abcabcdede"�� ���� ���, ���ڸ� 2�� ������ �߶� �����ϸ� "abcabc2de"�� ������, 3�� ������ �ڸ��ٸ� "2abcdede"�� �Ǿ� 3�� ������ ���� ª�� ���� ����� �˴ϴ�. �̶� 3�� ������ �ڸ��� �������� ���� ���ڿ��� �״�� �ٿ��ָ� �˴ϴ�.

������ ���ڿ� s�� �Ű������� �־��� ��, ���� ������ ������� 1�� �̻� ������ ���ڿ��� �߶� �����Ͽ� ǥ���� ���ڿ� �� ���� ª�� ���� ���̸� return �ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
s�� ���̴� 1 �̻� 1,000 �����Դϴ�.
s�� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.
����� ��
s	result
"aabbaccc"	7
"ababcdcdababcdcd"	9
"abcabcdede"	8
"abcabcabcabcdededededede"	14
"xababcdcdababcdcd"	17
����� ���� ���� ����
����� �� #1

���ڿ��� 1�� ������ �߶� �������� �� ���� ª���ϴ�.

����� �� #2

���ڿ��� 8�� ������ �߶� �������� �� ���� ª���ϴ�.

����� �� #3

���ڿ��� 3�� ������ �߶� �������� �� ���� ª���ϴ�.

����� �� #4

���ڿ��� 2�� ������ �ڸ��� "abcabcabcabc6de" �� �˴ϴ�.
���ڿ��� 3�� ������ �ڸ��� "4abcdededededede" �� �˴ϴ�.
���ڿ��� 4�� ������ �ڸ��� "abcabcabcabc3dede" �� �˴ϴ�.
���ڿ��� 6�� ������ �ڸ� ��� "2abcabc2dedede"�� �Ǹ�, �̶��� ���̰� 14�� ���� ª���ϴ�.

����� �� #5

���ڿ��� ���� �պ��� ������ ���̸�ŭ �߶�� �մϴ�.
���� �־��� ���ڿ��� x / ababcdcd / ababcdcd �� �ڸ��� ���� �Ұ��� �մϴ�.
�� ��� ��� ���ڿ��� �߶� ������� �����Ƿ� ���� ª�� ���̴� 17�� �˴ϴ�.

*/