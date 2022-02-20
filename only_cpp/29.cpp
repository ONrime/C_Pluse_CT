#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*

네트워크

*/

void FindNetwork(bool check[], vector<vector<int>> computers, int next) {
    if (check[next] == true) return;
    check[next] = true;
    for (int i = 0; i < computers.size(); i++) {
        if (next != i && computers[next][i] == 1 && check[i] == false) {
            FindNetwork(check, computers, i);
        }
    }
}

int solution28(int n, vector<vector<int>> computers) {
    int answer = 0;
    bool check[200] = { false, };
    for (int i = 0; i < n; i++) {
        if (check[i] == false) {
            answer++;
            FindNetwork(check, computers, i);
        }
    }
    cout << "answer: " << answer << endl;

    return answer;
}

/*int main()
{
    //solution28(3, { { 1, 1, 0 }, {1, 1, 0}, {0, 0, 1} }); // 2
    //solution28(3, { { 1, 1, 0 }, {1, 1, 1}, {0, 1, 1} }); // 1
    //solution28(4, { { 1, 0, 0, 1 }, {0, 1, 1, 0}, {0, 1, 1, 0}, {1, 1, 0, 1} }); // 1
    //solution28(4, { { 1, 0, 0, 1 }, {0, 1, 1, 1}, {0, 1, 1, 0}, {1, 1, 0, 1} }); // 1
    solution28(1, { { 1 } }); // 1
    solution28(5, { { 1, 0, 0, 1, 0 }, {0, 1, 1, 0, 0}, {0, 1, 1, 0, 0}, {1, 0, 0, 1, 1}, {0, 0, 0, 1, 1} }); // 2
    //solution28(6, { { 1, 0, 1, 1, 0, 0 }, {0, 1, 0, 0, 1, 1}, {1, 0, 1, 1, 1, 1}, {1, 0, 1, 1, 1, 1}
    //    , {0, 1, 1, 1, 1, 1}, {0, 1, 1, 1, 1, 1} }); // 1
}*/
