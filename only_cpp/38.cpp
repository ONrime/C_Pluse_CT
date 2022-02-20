#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
����

�÷��̵� �˰��� Ȱ��
�¸��� �й��� ��츦 �Ѵ� �����ؾ��Ѵ�.
�߿��Ѱ� ��ŭ ��⸦ ġ��°� �̴�. �¸��� �й踦 �����ϸ� �ݹ� ���´�.

*/
//
//
int solution_38_1(int n, vector<vector<int>> results) 
{
    int answer = 0;

    // n�� ���� �ʱ�ȭ �մϴ�.
    vector <vector <int>> temp(n, vector <int>(n, 0));

    for (int i = 0; i < results.size(); i++)
    {
        // �¸� ���� �� 1
        temp[results[i][0] - 1][results[i][1] - 1] = 1;
        // �й� ���� �� -1
        temp[results[i][1] - 1][results[i][0] - 1] = -1;
    }

    // �迭 ���
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
                // �¸��� ���� Ƚ�� ���
                if (temp[r][v] > 0 && temp[v][s] > 0)
                {
                    temp[r][s] = temp[r][v] + temp[v][s];
                }

                // �й迡 ���� Ƚ�� ���
                if (temp[r][v] < 0 && temp[v][s] < 0)
                {
                    temp[r][s] = temp[r][v] + temp[v][s];
                }
            }
        }
    }

    // �迭 ���
    // �¸�, �й� Ƚ���� ���� ������ ������ �迭�� ��������ϴ�.
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << " " << temp[i][j];
        }
        cout << endl;
    }
    cout << endl;

    // ���࿡ count�� n-1�̶�� 4���� ��⸦ �ߴٴ� ���̱� ������
    // ������ ���� �Ҽ� �ִ� �Ǵ��� answer�� ���մϴ�.
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