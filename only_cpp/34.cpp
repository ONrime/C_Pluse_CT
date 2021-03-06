#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

/*

프린터

solution_6_1처럼 pair를 쓰면 데이터를 더 쓰지만 빠르게 할 수 있다.
solution_6_2는 max_element를 이용한 풀이 이다.
다른 사람 풀이의 첫번째 꺼를 보면 solution_6_1보다 시간이 걸리지만 데이터를 덜 쓸 수 있는 풀이가 있다.

max_element는 배열중에서 가장 많은 값의 iter를 반환한다.

*/

int solution_6_1(vector<int> priorities, int location) {
    int answer = 0;

    // 최대 값으로 정렬하고 (사실은 최소순으로 정렬한 거다. vector는 front()가 없어서 back으로 활용하기 위해 최소순으로 정렬했다.)
    vector<int> max = priorities;  
    sort(max.begin(), max.end()); 

    queue<pair<int, int>> temp; // temp에 위치와 크기(priorities)를 넣는다.
    for (int i = 0; i < priorities.size(); i++) {
        temp.push(pair<int, int>(i, priorities[i]));
    }
    while (!temp.empty()) 
    {
        int front = temp.front().second;
        int position = temp.front().first;
        temp.pop();
        if (max.back() != front) 
        { // 최대가 아니면
            temp.push(pair<int, int>(position, front));
        }
        else 
        { // 최대라면 카운트하라.
            answer++;
            if (position == location) break; // 찾는 위치값이면 나가라.
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
        else { // 나갈 때
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

/* 과거에 풀었던 문제방식 */
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
