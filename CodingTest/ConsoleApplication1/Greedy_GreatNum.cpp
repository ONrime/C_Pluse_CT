#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include<string>

using namespace std;

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* number, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
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

큰 수 만들기

문제 설명
어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자를 구하려 합니다.

예를 들어, 숫자 1924에서 수 두 개를 제거하면 [19, 12, 14, 92, 94, 24] 를 만들 수 있습니다. 이 중 가장 큰 숫자는 94 입니다.

문자열 형식으로 숫자 number와 제거할 수의 개수 k가 solution 함수의 매개변수로 주어집니다. number에서 k 개의 수를 제거했을 때 만들 수 있는 수 중 가장 큰 숫자를 문자열 형태로 return 하도록 solution 함수를 완성하세요.

제한 조건
number는 1자리 이상, 1,000,000자리 이하인 숫자입니다.
k는 1 이상 number의 자릿수 미만인 자연수입니다.
입출력 예
number	k	return
"1924"	2	"94"
"1231234"	3	"3234"
"4177252841"	4	"775841"

*/