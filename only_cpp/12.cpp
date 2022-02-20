#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool gym_compare(int a, int b) {
    return a > b;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    vector <int> give;

    sort(lost.begin(), lost.end(), gym_compare);
    sort(reserve.begin(), reserve.end());

    give.push_back(0);
    for (auto it = reserve.begin(); it != reserve.end(); it++) {
        if (lost.empty()) {
            break;
        }
        if (give.back() == lost.back()) { lost.pop_back(); }
        if (give.back() == (*it)) { continue; }

        if ((*it) == lost.back() - 1 || (*it) == lost.back() + 1 || (*it) == lost.back()) {
            int x = 0;
            (*it) > lost.back() ? x = (*it) : x = lost.back();
            give.push_back(x);
            lost.pop_back();
            answer++;
        }
        else if ((*it) > lost.back()) {
            lost.pop_back();
            it--;
        }
    }

    
    return answer;
}

/*int main()
{
    //cout << "answer: " << solution(5, { 2, 4 }, { 1, 3, 5 }) << endl; // 5
    //cout << "answer: " << solution(8, { 2, 40, 50 }, { 1, 3, 5, 49 }) << endl; // 7
    //cout << "answer: " << solution(8, { 2, 40, 49 }, { 1, 3, 5, 49 }) << endl; // 7
    cout << "answer: " << solution(4, { 3, 1, 2 }, { 2, 4, 3 }) << endl; // 3
    //cout << "answer: " << solution(2, { 1 }, { 4 }) << endl; // 1
    //cout << "answer: " << solution(5, { 2, 4 }, { 3 }) << endl; // 4
    //cout << "answer: " << solution(3, { 3 }, { 1 }) <<endl; // 2
    //cout << "answer: " << solution(4, { 3, 1 }, { 2, 4 }) <<endl; // 4
    //cout << "answer: " << solution(2, { 1 }, { 2 }) <<endl; // 2
    cout << "answer: " << solution(5, { 2, 3, 4 }, { 1, 2, 3 }) <<endl; // 4
    cout << "answer: " << solution(5, { 1, 2, 3 }, { 2, 3, 4 }) <<endl; // 4
}*/

/*

Ã¼À°º¹

*/