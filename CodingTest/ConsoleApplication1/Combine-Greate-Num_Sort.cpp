#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct greater_num { // 정렬 방식( 정렬하려는 수와 합쳐서 가장 큰 수를 찾는다. )
    bool operator()(string a, string b) {
        string aa = a + b, bb = b + a;
        int aa_i = stoi(aa), bb_i = stoi(bb);
        return aa_i < bb_i;
    }
};
string solution(vector<int> numbers) {
    string answer = "";
    priority_queue<string, vector<string>, greater_num> num_s;
    vector<int>::iterator it_num;
    for (it_num = numbers.begin(); it_num != numbers.end(); it_num++) {
        num_s.push(to_string(*it_num));
    }
    if (num_s.top() == "0") { // 가장 앞자리가 0이면 결과가 0 한 자리만 나오게 한다.
        answer = "0";
        return answer;
    }
    for (int i = 0; i < numbers.size(); i++) {
        answer += num_s.top();
        num_s.pop();
    }
    //cout << "answer: " << answer << endl;
    return answer;
}

/*int main()
{
    //solution16({ 6, 10, 2 }); // 6210
    //solution16({ 3, 30, 34, 5, 9 }); // 9534330
    //solution16({ 151, 15, 1 }); // 9534330
    //solution16({ 10, 101 }); // 10110
    //solution16({ 1, 11, 111, 1111 }); // 1111111111
    solution({ 0, 0, 0, 0, 0, 0 }); // 0
   // solution16({ 0, 5, 10, 15, 20 }); // 52015100
    //solution16({ 1000, 0, 5, 99, 100 }); // 99510010000
    solution({ 90,908,89,898,10,101,1,8,9 }); // 990908898988110110
    solution({ 40, 403 }); // 40403
    solution({ 403, 40 }); // 40403

}*/


/*

가장 큰 수

문제 설명
0 또는 양의 정수가 주어졌을 때, 정수를 이어 붙여 만들 수 있는 가장 큰 수를 알아내 주세요.

예를 들어, 주어진 정수가 [6, 10, 2]라면 [6102, 6210, 1062, 1026, 2610, 2106]를 만들 수 있고, 이중 가장 큰 수는 6210입니다.

0 또는 양의 정수가 담긴 배열 numbers가 매개변수로 주어질 때, 순서를 재배치하여 만들 수 있는 가장 큰 수를 문자열로 바꾸어 return 하도록 solution 함수를 작성해주세요.

제한 사항
numbers의 길이는 1 이상 100,000 이하입니다.
numbers의 원소는 0 이상 1,000 이하입니다.
정답이 너무 클 수 있으니 문자열로 바꾸어 return 합니다.
입출력 예
numbers	return
[6, 10, 2]	"6210"
[3, 30, 34, 5, 9]	"9534330"

*/


/*

자리 수별로 비교하는 방법으로 시도를 해봤지만 너무 무식한 방식이었다.
첫째 자리 수 만으로 비교하다가 첫째 자리 수가 똑같은 값이면 어떻게 처리 해야 되는지에 대한 경우수가 생각보다 다양해서
많이 방황을 했고 만들고 보니 오래걸릴 뿐더러 더럽게 만들어져서 괴상한걸 만든거 같다.

struct greater_num {
    bool operator()(int &a, int &b){
        string a_s = to_string(a), b_s = to_string(b);
        int a_size = a_s.size(), b_size = b_s.size();
        bool ans = false;
        
        a_size > 1 ? a_size = pow(10, a_size-1) : a_size = 1;
        b_size > 1 ? b_size = pow(10, b_size-1) : b_size = 1;
        
        int aa = 0, bb = 0, a_ = a, b_ = b;
        while (true) {
            a_ > 0 ? aa = a_ / a_size : aa = a_;
            b_ > 0 ? bb = b_ / b_size : bb = b_;

           

            if (aa == bb) {
                if (a_size > 1) {
                    a_ = a_ % a_size;
                    a_size = a_size / 10;
                }
                else {
                    a_size = 1;
                }
                if (b_size > 1) {
                    b_ = b_ % b_size;
                    b_size = b_size / 10;
                }
                else {
                    b_size = 1;
                }
                continue;
            }

            return aa < bb;
        }
        return a < b;
    }
};

*/