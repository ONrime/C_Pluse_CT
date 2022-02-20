#include <string>
#include <vector>
#include <stack>
#include <iostream>

/*

주식 설명

중요한건 크기순으로 증가하다 낮은 값을 만나게 되면 
그 낮은 값은 지나온 다른 값들의 기준(떨어진 가격)일 수 있다.

*/

using namespace std;

vector<int> solution_7_1(vector<int> prices) {
    vector<int> answer;
    stack<int> prices_comparison, prices_stack;
    int fullNum = prices.size();

    vector<int>::iterator prices_it;
    for (prices_it = prices.end() - 1; prices_it != prices.begin(); prices_it--) {
        prices_stack.push(*prices_it);
    }
    prices_stack.push(*prices.begin());

    while (true) {
        int count = 0;
        int top = prices_stack.top();
        prices_stack.pop();
        while (true) {
            if (prices_stack.empty()) {
                int prices_comparison_size = prices_comparison.size();
                for (int i = 0; i < prices_comparison_size; i++) {
                    prices_stack.push(prices_comparison.top());
                    prices_comparison.pop();
                }
                break;
            }
            if (top <= prices_stack.top()) {
                count++;
                prices_comparison.push(prices_stack.top());
                prices_stack.pop();
            }
            else {
                count++;
                int prices_comparison_size = prices_comparison.size();
                for (int i = 0; i < prices_comparison_size; i++) {
                    prices_stack.push(prices_comparison.top());
                    prices_comparison.pop();
                }
                break;
            }
        }
        answer.push_back(count);
        if (fullNum == answer.size()) {
            break;
        }
    }
    return answer;
}

vector<int> solution_7_2(vector<int> prices) {
    vector<int> answer;

    int count = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = i + 1; j < prices.size(); j++)
        {
            count++;
            if (prices[i] > prices[j])
            {
                break;
            }
        }
        answer.push_back(count);
        count = 0;
    }

    cout << "answer: ";
    for (auto a : answer) cout << a << ", ";
    cout << endl;

    return answer;
}

vector<int> solution_7_3(vector<int> prices) {
    vector<int> answer(prices.size());

    stack<int> prices_check;

    /*
    값을 비교 할때 크기순으로 커질떄 스택에 쌓는다.
    그 떄 작은 값이 나오면 쌓인 스택의 값 순서로 작은 값과 비교 한다.
    작은 값보다 스택에 쌓인 값보다 작으면 그 값도 변화가 일어난것 이기 때문에 계산을 한다.
    
    1. 크기순으로 커지면 스택에 쌓는다.
    2. 작은 값이 나오면 스택에서 pop하는 순으로 스택에 있는 모든 값과 그 작은 값을 비교한다.
    3. 스택에 있는 값과 작은 값을 비교 했을 때 스택에 있는 값이 더 크면 
        변화가 일어난 것이기 때문에 계산을 한다.
    */

    for (int i = 0; i < prices.size(); i++)
    {
        while (!prices_check.empty() && prices[prices_check.top()] > prices[i])
        { //  작은 값이 나오면 스택에서 pop하는 순으로 스택에 있는 모든 값과 그 작은 값을 비교한다.
            //스택에 있는 값과 작은 값을 비교 했을 때 스택에 있는 값이 더 크면 변화가 일어난 것이기 때문에 계산을 한다.
            answer[prices_check.top()] = i - prices_check.top();
            prices_check.pop();
        }
        prices_check.push(i); // 크기순으로 커지면 스택에 쌓는다.
    }

    // 그 외의 값들은 변화가 없는 값들이다. 
    while (!prices_check.empty()) 
    {
        answer[prices_check.top()] = prices.size() - prices_check.top() - 1;
        prices_check.pop();
    }

    cout << "answer: ";
    for (auto a : answer) cout << a << ", ";
    cout << endl;

    return answer;
}

int main()
{
    solution_7_1({ 1, 2, 3, 2, 3 }); // 4, 3, 1, 1, 0
    solution_7_2({ 1, 2, 3, 2, 3 }); // 4, 3, 1, 1, 0
    solution_7_3({ 1, 2, 3, 2, 3 }); // 4, 3, 1, 1, 0
    //solution_7_1({ 5, 8, 6, 2, 4, 1 }); //3, 1, 1, 2, 1, 0
}