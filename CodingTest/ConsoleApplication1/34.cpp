#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution_34_1(int n, long long k) {
    vector<int> answer;
    vector<int> temp;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        temp.push_back(i + 1);
    }

    do {
        count++;
        if (count == (int)k) 
        {
            
        }
        for (auto it = temp.begin(); it != temp.end(); ++it) {
            if (count == (int)k)
            {
                answer.push_back(*it);
            }
            
            cout << *it << ' ';
        }
        cout << endl;
    } while (next_permutation(temp.begin(), temp.end()));
    cout << "count: " << count << endl;
    cout << "answer: ";
    for (auto it = answer.begin(); it != answer.end(); it++)
    {
        cout << *it << " ";
    }
    return answer;
}

long long facto(int n)
{
    long long temp = 1;
    for (int i = 2; i < n+1; i++) 
    {
        temp *= i;
    }
    return temp;
}

vector<int> solution_34_2(int n, long long k) {
    vector<int> answer;
    long long temp = 0;
    int count = 0;
    long long one = 0;
    //cout << "facto: " << facto(n) << endl;

    vector<int> test;
    for (int i = 1; i < n + 1; i++)
    {
        test.push_back(i);
        //cout << "i: " << i << endl;
    }

    for (int j = n; j != 0; j--)
    {
        //cout << "j: " << j << endl;
        count = 0;
        temp -= one;
        one = facto(j - 1);
        for (int i = 0; i < n; i++)
        {
            temp += one;
            count++;
            if (temp >= k)
            {
                break;
            }
        }
        //cout << "test: " << *(test.begin() + (count - 1));
        answer.push_back(*(test.begin() + (count - 1)));
        test.erase(test.begin() + (count - 1));
    }
    

    

    cout << "answer: ";
    for (auto it = answer.begin(); it != answer.end(); it++)
    {
        cout << *it << " ";
    }
    return answer;
}


/*int main()
{
    //solution_34_1(5, 78); // 3, 1, 2 // 4 1 5 3 2
    solution_34_2(5, 78); // 3, 1, 2
    solution_34_2(3, 5); // 3, 1, 2
    //solution_34_2(20, 78); // 3, 1, 2
}*/

// 줄 서는 방법