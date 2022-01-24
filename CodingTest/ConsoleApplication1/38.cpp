#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
순위

플로이드 알고리즘 활용
승리와 패배의 경우를 둘다 생각해야한다.
중요한건 얼만큼 경기를 치뤘는가 이다. 승리와 패배를 유추하면 금방 나온다.

*/
//
//
int solution_38_1(int n, vector<vector<int>> results) 
{
    int answer = 0;

    // n의 수로 초기화 합니다.
    vector <vector <int>> temp(n, vector <int>(n, 0));

    for (int i = 0; i < results.size(); i++)
    {
        // 승리 했을 때 1
        temp[results[i][0] - 1][results[i][1] - 1] = 1;
        // 패배 했을 때 -1
        temp[results[i][1] - 1][results[i][0] - 1] = -1;
    }

    // 배열 출력
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << " " << temp[i][j];
        }
        cout << endl;
    }
    cout << endl;

    for (int v = 0; v < n; v++)
    {
        for (int r = 0; r < n; r++)
        {
            for (int s = 0; s < n; s++)
            {
                // 승리에 대한 횟수 계산
                if (temp[r][v] > 0 && temp[v][s] > 0)
                {
                    temp[r][s] = temp[r][v] + temp[v][s];
                }

                // 패배에 대한 횟수 계산
                if (temp[r][v] < 0 && temp[v][s] < 0)
                {
                    temp[r][s] = temp[r][v] + temp[v][s];
                }
            }
        }
    }

    // 배열 출력
    // 승리, 패배 횟수가 각자 더해진 형태의 배열이 만들어집니다.
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << " " << temp[i][j];
        }
        cout << endl;
    }
    cout << endl;

    // 만약에 count가 n-1이라면 4번의 경기를 했다는 뜻이기 때문에
    // 순위를 유추 할수 있다 판단해 answer를 더합니다.
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = 0; j < n; j++)
        {
            if (temp[j][i] != 0)count++;
        }
        if (count == n-1) answer++;
    }
    
    return answer;
}

/*int main()
{
    cout << "solution: " << solution_38_1(5, { {4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5} }) << endl; // 2
    cout << "solution: " << solution_38_1(5, { {1, 2}, {4, 5}, {3, 4}, {2, 3} }) << endl; // 5
}*/