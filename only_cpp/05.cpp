#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

/*

기능개발

큐와 스택을 생각하며 풀자
*/

vector<int> solution_5_1(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> pro_queue;
    queue<int> speeds_queue;

    vector<int>::iterator pro_it;
    vector<int>::iterator speeds_it = speeds.begin();
    for (pro_it = progresses.begin(); pro_it != progresses.end(); pro_it++) {
        pro_queue.push(*pro_it);
        speeds_queue.push(*speeds_it);
        speeds_it++;
    }
    float day = 0.0f;
    while (pro_queue.size() != 0) {
        int front = pro_queue.front();
        day += ceil((float)(100 - front) / (float)speeds_queue.front());
        int count = 1;
        pro_queue.pop();
        speeds_queue.pop();

        int pro_queue_size = pro_queue.size();
        for (int i = 0; i < pro_queue_size; i++) {
            int pro_f = pro_queue.front();
            int speeds_f = speeds_queue.front();
            if ((day * speeds_f) + pro_f >= 100) {
                count++;
                pro_queue.pop();
                speeds_queue.pop();
            }
            else {
                break;
            }
        }
        answer.push_back(count);
    }

    cout << "answer: ";
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << "\n";

    return answer;
}

vector<int> solution_5_2(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue<int> progresses_queue;
    // 지나야 되는 날을 구한다.
    float day = ceil((float)(100 - progresses[0]) / speeds[0]);
    for (int i = 0; i < progresses.size(); i++)
    {
        float sideday = ceil((float)(100 - progresses[i]) / speeds[i]);
        // day = (99 - progresses[i]) / speeds[i] + 1; ceil 안쓰고 하는 방법
        if (day < sideday) // 앞에 있는 것보다 지나야 되는 날이 적으면 큐를 반출시킨다.
        {
            answer.push_back(progresses_queue.size()); // 큐의 크기를 적고
            while (progresses_queue.size() != 0) progresses_queue.pop(); // 큐를 반출
            day = sideday;
        }
        progresses_queue.push(progresses[i]);
    }
    answer.push_back(progresses_queue.size());

    cout << "answer: ";
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << "\n";
    return answer;
}

/*int main()
{
   // solution_5_1({ 93, 30, 55 }, { 1, 30, 5 }); // 2 1
    //solution_5_2({ 93, 30, 55 }, { 1, 30, 5 }); // 2 1
    //solution_5_1({ 95, 90, 99, 99, 80, 99 }, { 1, 1, 1, 1, 1, 1 }); // 1 3 2
    //solution_5_2({ 95, 90, 99, 99, 80, 99 }, { 1, 1, 1, 1, 1, 1 }); // 1 3 2
    solution_5_2({ 20, 10, 30, 5, 55, 60, 10 }, { 20, 10, 30, 5, 10, 10, 10 }); // 1 2 3 1 ?? 1 2 4
    //solution_5_2({ 99, 1, 99, 1 }, { 1, 1, 1, 1 }); // 1 3
    //solution_5_1({ 93 }, { 1 }); // 1
}*/
