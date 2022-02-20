#include <string>
#include <vector>
#include <stack>
#include <iostream>

/*

�ֽ� ����

�߿��Ѱ� ũ������� �����ϴ� ���� ���� ������ �Ǹ� 
�� ���� ���� ������ �ٸ� ������ ����(������ ����)�� �� �ִ�.

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
    ���� �� �Ҷ� ũ������� Ŀ���� ���ÿ� �״´�.
    �� �� ���� ���� ������ ���� ������ �� ������ ���� ���� �� �Ѵ�.
    ���� ������ ���ÿ� ���� ������ ������ �� ���� ��ȭ�� �Ͼ�� �̱� ������ ����� �Ѵ�.
    
    1. ũ������� Ŀ���� ���ÿ� �״´�.
    2. ���� ���� ������ ���ÿ��� pop�ϴ� ������ ���ÿ� �ִ� ��� ���� �� ���� ���� ���Ѵ�.
    3. ���ÿ� �ִ� ���� ���� ���� �� ���� �� ���ÿ� �ִ� ���� �� ũ�� 
        ��ȭ�� �Ͼ ���̱� ������ ����� �Ѵ�.
    */

    for (int i = 0; i < prices.size(); i++)
    {
        while (!prices_check.empty() && prices[prices_check.top()] > prices[i])
        { //  ���� ���� ������ ���ÿ��� pop�ϴ� ������ ���ÿ� �ִ� ��� ���� �� ���� ���� ���Ѵ�.
            //���ÿ� �ִ� ���� ���� ���� �� ���� �� ���ÿ� �ִ� ���� �� ũ�� ��ȭ�� �Ͼ ���̱� ������ ����� �Ѵ�.
            answer[prices_check.top()] = i - prices_check.top();
            prices_check.pop();
        }
        prices_check.push(i); // ũ������� Ŀ���� ���ÿ� �״´�.
    }

    // �� ���� ������ ��ȭ�� ���� �����̴�. 
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