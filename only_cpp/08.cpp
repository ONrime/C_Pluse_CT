#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


/*

구명보트

*/

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());

    int i = 0;
    while (people.size()>i) {
        /*if (people.end() == people.begin() + i) {
            break;
        }*/
        if (limit < (people[i] + people.back())) {
            people.pop_back();
            answer++;
        }
        else {
            people.pop_back();
            i++;
            answer++;
        }
    }


    return answer;
}

/*int main()
{
    cout << "answer: " << solution({ 70, 50, 80, 50 }, 100) << "\n"; // 3
    cout << "answer: " << solution({ 70, 50, 80, 50, 50 }, 100) << "\n"; // 4
    cout << "answer: " << solution({ 70, 80, 50 }, 100) << "\n"; // 3
    cout << "answer: " << solution({ 40, 40, 80 }, 160) << "\n"; // 2
}*/
