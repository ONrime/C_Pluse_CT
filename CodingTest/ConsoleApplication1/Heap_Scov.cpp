#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

/*int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> scov;

    vector<int>::iterator it_scoville;
    for (it_scoville = scoville.begin(); it_scoville != scoville.end(); it_scoville++) {
        scov.push(*it_scoville);
    }

    while (true) {
        if (scov.top() < K) {
            int top_1 = scov.top();
            scov.pop();
            int top_2 = scov.top();
            scov.pop();

            int new_scov = top_1 + (top_2 * 2);
            scov.push(new_scov);
            answer++;
        }
        else {
            break;
        }
        if (scov.size() < 2 && scov.top() < K) {
            answer = -1;
            break;
        }
    }

    return answer;
}*/

/*int main()
{
    cout << "answer: " << solution({ 1, 2, 3, 9, 10, 12 }, 7) << "\n"; // 2
    cout << "answer: " << solution({ 1, 1, 1 }, 4) << "\n"; // 2
    cout << "answer: " << solution({ 10, 10, 10, 10, 10 }, 100) << "\n"; // 4
    cout << "answer: " << solution({ 1, 2, 3, 9, 10, 12 }, 7) << "\n"; // 2
    cout << "answer: " << solution({ 0, 0, 3, 9, 10, 12 }, 7000) << "\n"; // -1
    cout << "answer: " << solution({ 0, 0 }, 0) << "\n"; // 0
    cout << "answer: " << solution({ 0, 0 }, 1) << "\n"; // -1
    cout << "answer: " << solution({ 1, 0 }, 1) << "\n"; // 1
}*/

/*

´õ ¸Ê°Ô

*/