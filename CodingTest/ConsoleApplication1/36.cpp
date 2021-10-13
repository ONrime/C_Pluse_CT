#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution_36_1(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    vector<vector<int>> temp(n, vector<int>(m));

    sort(puddles.begin(), puddles.end());
    auto iter = puddles.begin();

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (iter != puddles.end() && (*iter)[0] - 1 == i - 1 && (*iter)[1] - 1 == j - 1)
            {
                iter++;
                continue;
            }
            if (i == 1 || j == 1)
            {
                temp[i - 1][j - 1] = 1;
            }
            else 
            {
                temp[i - 1][j - 1] += temp[i - 2][j - 1];
                temp[i - 1][j - 1] += temp[i - 1][j - 2];
            }
            temp[i - 1][j - 1] = temp[i - 1][j - 1] % 1000000007;
        }
    }

    cout << "--temp--" << endl;
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < m; b++) {
            cout << " " << temp[a][b] << " ";
        }
        cout << endl;
    }

    answer = temp[n - 1][m - 1];
    cout << "answer: " << answer % 1000000007 << endl;
    return answer;
}

/*

int solution_36_1(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    vector<vector<int>> temp(n, vector<int>(m));

    sort(puddles.begin(), puddles.end());
    auto iter = puddles.begin();

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (iter != puddles.end() && (*iter)[0] - 1 == i - 1 && (*iter)[1] - 1 == j - 1)
            {
                iter++;
                cout << " " << temp[i - 1][j - 1];
                continue;
            }
            if (i == 1 || j == 1)
            {
                temp[i - 1][j - 1] = 1;
                //temp[j - 1][i - 1] = 1;
            }
            else
            {
                temp[i - 1][j - 1] += temp[(i - k) - 1][j - 2];
                for (int k = 0; k < 2; k++)
                {
                    //temp[i - 1][j - 1] += temp[(i - k) - 1][j - 2];

                    //temp[j - 1][i - 1] += temp[(i - k) - 1][j - 2];
                    //cout << "temp: " << temp[i - 1][j - 1] << endl;
                    //cout << "temp2: " << i - k << " " << j - 1 << " " << temp[(i - k) - 1 ][(j - 1) - 1] << endl;
                }
            }
            cout << " " << temp[i - 1][j - 1];
        }
        cout << endl;
    }
    cout << "--temp--"<< endl;
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < m; b++) {
            cout << " " << temp[a][b] << " ";
        }
        cout << endl;
    }

    answer = temp[n - 1][m - 1];
    cout << "answer: " << answer << endl;
    /*for (int l = 0; l < puddles.size(); l++)
    {
        cout << "puddles: " << ((m - puddles[l][0]) + 1) << " " << ((n - puddles[l][1]) + 1) << endl;
        int min = temp[((m - puddles[l][0]) + 1) - 1][((n - puddles[l][1]) + 1) - 1];

        cout << "min: " << min << endl;
        if (!(puddles[l][0] == m || puddles[l][1] == n))
        {

        }
        else if(puddles[l][0] - 1) {
            //min += 2;
        }

        if ((n - ((n - puddles[l][1]) + 1)) + 1 != n)
        {

        }
        else
        {
            //min -= 1;
        }
        min *= (n - ((n - puddles[l][1]) + 1)) + 1;
        cout << "min: " << min << " " << (n - ((n - puddles[l][1]) + 1)) + 1 << endl;
        cout << "min: " << min << " " << (n - puddles[l][1]) + 1 << endl;
        answer -= min;

        /*int max_l = 0;
        puddles[l][0]-1 >= puddles[l][1]-1 ? max_l = puddles[l][0] : max_l = puddles[l][1];
        cout << "max_l: " << max_l << endl;
        if (max_l + 1 == n)
        {
            answer -= (temp[puddles[l][0] - 1][puddles[l][1] - 1]);
        }
        else {
            answer -= (temp[puddles[l][0] - 1][puddles[l][1] - 1]) * 2;

        }*/


        /*cout << "---answer: " << temp[puddles[l][0] - 1][puddles[l][1] - 1] * 2 << endl;
        cout << "puddles: " << puddles[l][0] << " " << puddles[l][1] << endl;
        cout << "temp: " << temp[puddles[l][0] - 1][puddles[l][1] - 1] << endl;
    }


cout << "answer: " << answer << endl;
cout << endl;
return answer;
}

*/

int main()
{
    //solution_36_1(4, 3, { {2,2} }); // 4
    //solution_36_1(4, 4, { {2, 3}, {4, 2} }); // 7
    //solution_36_1(3, 3, { {2, 2} }); // 2
    //solution_36_1(3, 3, { {2, 3} }); // 3
    //solution_36_1(3, 3, { {3, 2} }); // 3
    //solution_36_1(3, 3, { {1, 3} }); // 5
    //solution_36_1(3, 3, { {1, 3}, {3, 1} }); // 4
    //solution_36_1(3, 3, { {1, 3}, {3, 1}, {2, 3}, {2, 2}}); // 4
    
    solution_36_1(3, 3, { {1, 3}, {3, 1}, {2, 3}}); // 2
    solution_36_1(3, 3, { {1, 3}, {3, 1}, {2, 3}}); // 2
    solution_36_1(3, 3, { {1, 3}, {3, 1}, {2, 3}, {2, 1}}); // 1
    solution_36_1(7, 4, { {2, 1}, {2, 2}, {2, 3}, {4, 2}, {4, 3}, {4, 4}, {6, 2}, {6, 3} }); // 0
    solution_36_1(4, 4, { {3, 2}, {2, 4}}); // 7
}