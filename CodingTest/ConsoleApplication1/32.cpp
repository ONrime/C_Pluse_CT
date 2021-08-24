#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

/*

������

solution_6_1ó�� pair�� ���� �����͸� �� ������ ������ �� �� �ִ�.
solution_6_2�� max_element�� �̿��� Ǯ�� �̴�.
�ٸ� ��� Ǯ���� ù��° ���� ���� solution_6_1���� �ð��� �ɸ����� �����͸� �� �� �� �ִ� Ǯ�̰� �ִ�.

max_element�� �迭�߿��� ���� ���� ���� iter�� ��ȯ�Ѵ�.

*/

int solution_6_1(vector<int> priorities, int location) {
    int answer = 0;

    // �ִ� ������ �����ϰ� (����� �ּҼ����� ������ �Ŵ�. vector�� front()�� ��� back���� Ȱ���ϱ� ���� �ּҼ����� �����ߴ�.)
    vector<int> max = priorities;  
    sort(max.begin(), max.end()); 

    queue<pair<int, int>> temp; // temp�� ��ġ�� ũ��(priorities)�� �ִ´�.
    for (int i = 0; i < priorities.size(); i++) {
        temp.push(pair<int, int>(i, priorities[i]));
    }
    while (!temp.empty()) 
    {
        int front = temp.front().second;
        int position = temp.front().first;
        temp.pop();
        if (max.back() != front) 
        { // �ִ밡 �ƴϸ�
            temp.push(pair<int, int>(position, front));
        }
        else 
        { // �ִ��� ī��Ʈ�϶�.
            answer++;
            if (position == location) break; // ã�� ��ġ���̸� ������.
            max.pop_back();
        }
    }

    cout << "answer: " << answer << endl;
    return answer;
}

int solution_6_2(vector<int> priorities, int location) {
    int answer = 0;

    queue<pair<int, int>> temp;
    for (int i = 0; i < priorities.size(); i++) {
        temp.push(pair<int, int>(i, priorities[i]));
    }
    while (!temp.empty()) {
        int front = temp.front().second;
        int position = temp.front().first;
        temp.pop();
        if (*max_element(priorities.begin(), priorities.end()) != front) {
            temp.push(pair<int, int>(position, front));
        }
        else { // ���� ��
            answer++;
            if (position == location) break;
            priorities[position] = 0;
        }
    }

    cout << "answer: " << answer << endl;
    return answer;
}

/*int main()
{
    solution_6_2({ 2, 1, 3, 2 }, 2); // 1
    solution_6_2({ 1, 1, 9, 1, 1, 1 }, 0); // 5
    solution_6_2({ 1, 1, 3, 1, 4 }, 3); // 5
}*/

/* ���ſ� Ǯ���� ������� */
/*bool check_loc(int& x) {
    bool check = false;
    if (x > 10) {
        x -= 10;
        check = true;
    }
    return check;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> print_p, print_check;
    bool loop_out = false;

    vector<int>::iterator it_priorities;
    for (it_priorities = priorities.begin(); it_priorities != priorities.end(); it_priorities++) {
        if (priorities.begin() + location == it_priorities) {
            *it_priorities += 10;
        }
        print_p.push(*it_priorities);
    }

    while (!loop_out) {
        int mid = print_p.front();
        bool check = check_loc(mid);
        print_p.pop();

        int print_p_size = print_p.size();
        if (print_p_size == 0) {
            answer++;
            loop_out = true;
        }
        for (int i = 0; i < print_p_size; i++) {
            int front = print_p.front();
            check_loc(front);

            if (mid < front) {
                if (check) {
                    mid += 10;
                }
                print_p.push(mid);
                int print_check_size = print_check.size();
                for (int k = 0; k < print_check_size; k++) {
                    print_p.push(print_check.front());
                    print_check.pop();
                }
                break;
            }
            else {
                print_check.push(print_p.front());
                print_p.pop();
                if (print_p.empty()) {
                    answer++;
                    if (check) {
                        loop_out = true;
                        break;
                    }
                    print_p.swap(print_check);
                }
            }
        }
    }
    return answer;
}*/
