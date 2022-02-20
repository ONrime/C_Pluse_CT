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