#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

/*

게임 맵 최단거리

*/

/* DFS 깊이 우선 탐색 방식 */
void FindEnd(vector<vector<int>> maps, int i, int j, bool check[][100], int count, int& answer, int endi, int endj)
{
    if (i == endi && j == endj && answer > count) {
        answer = count;
        return;
    }
    if (j < endj && maps[i][j + 1] == 1 && check[i][j + 1] == false) { // 동
        check[i][j + 1] = true;
        FindEnd(maps, i, j + 1, check, count+1, answer, endi, endj);
        check[i][j + 1] = false;
    }
    else if (i < endi && maps[i + 1][j] == 1 && check[i + 1][j] == false) { // 남
        check[i + 1][j] = true;
        FindEnd(maps, i +1 , j, check, count + 1, answer, endi, endj);
        check[i + 1][j] = false;
    }
    else if (j > 0 && maps[i][j-1] && check[i][j - 1] == false) { // 서
        check[i][j - 1] = true;
        FindEnd(maps, i, j - 1, check, count + 1, answer, endi, endj);
        check[i][j - 1] = false;
    }
    else if (i > 0 && maps[i-1][j] && check[i - 1][j] == false) { // 북
        check[i - 1][j] = true;
        FindEnd(maps, i - 1, j, check, count + 1, answer, endi, endj);
        check[i - 1][j] = false;
    }
}

/* BFS 너비 우선 탐색 방식 */
int FindEnd2(vector<vector<int>> maps, bool check[][100], int endi, int endj)
{
    int c = 1;
    queue<pair<int, int>> tile;
    tile.push(pair<int, int>(0, 0));
    check[0][0] = true;
    while (!tile.empty()) {
        int size = tile.size();
        for (int i = 0; i < size; i++) {
            pair<int, int> a = tile.front();
            if (a.first == endi && a.second == endj) {
                return c;
            }
            tile.pop();
            a.first; // i
            a.second; // j
            if (a.second < endj && maps[a.first][a.second + 1] == 1 && check[a.first][a.second + 1] == false) { // 동
                check[a.first][a.second + 1] = true;
                tile.push(pair<int, int>(a.first, a.second + 1));
            }
            if (a.first < endi && maps[a.first + 1][a.second] == 1 && check[a.first + 1][a.second] == false) { // 남
                check[a.first + 1][a.second] = true;
                tile.push(pair<int, int>(a.first + 1, a.second));
            }
            if (a.second > 0 && maps[a.first][a.second - 1] == 1 && check[a.first][a.second - 1] == false) { // 서
                check[a.first][a.second - 1] = true;
                tile.push(pair<int, int>(a.first, a.second - 1));
            }
            if (a.first > 0 && maps[a.first - 1][a.second] == 1 && check[a.first - 1][a.second] == false) { // 북
                check[a.first - 1][a.second] = true;
                tile.push(pair<int, int>(a.first - 1, a.second));
            }
        }
        c++;
    }
    return 0;
}

int solution32(vector<vector<int>> maps)
{
    int answer = 1000;
    bool check[100][100] = { {false, }, };
    //FindEnd(maps, 0, 0, check, 1, answer, maps.size()-1, maps[0].size()-1);
    answer=FindEnd2(maps, check, maps.size()-1, maps[0].size()-1);
    if (answer == 0) answer = -1;
    cout << "answer: " << answer << endl;
    return answer;
}

/*int main()
{
    solution32({ {1, 0, 1, 1, 1},{1, 0, 1, 0, 1 }, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1},{0, 0, 0, 0, 1} }); // 11
    solution32({ {1, 0, 1, 1, 1},{1, 0, 1, 0, 1 }, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 0},{0, 0, 0, 0, 1} }); // -1
}*/
