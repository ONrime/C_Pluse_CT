#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 배
* 정렬 중요
* 탐욕 알고리즘
*/
int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m, answer = 0;
    vector<int> nn;
    vector<int> mm;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int input_n;
        cin >> input_n;
        nn.push_back(input_n);
    }

    sort(nn.begin(), nn.end());
    /*for (int i = 0; i < n; i++)
    {
        cout << nn[i] << endl;
    }*/

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int input_m;
        cin >> input_m;
        mm.push_back(input_m);
    }

    sort(mm.begin(), mm.end());
    /*for (int i = 0; i < m; i++)
    {
        cout << mm[i] << endl;
    }*/

    if (mm.back() > nn.back())
    {
        cout << -1;
        return 0;
    }
    
    while (mm.size() != 0)
    {
        for (int i = nn.size() - 1; i > -1; i--)
        {
            for (int j = mm.size() - 1; j > -1; j--)
            {
                if (mm.front() > *(nn.begin() + i)) break;
                //cout << "nn: " << *(nn.begin() + i) << endl;
                //cout << "mm: " << *(mm.begin() + j) << endl;
                if (*(nn.begin() + i) >= *(mm.begin() + j))
                {
                    mm.erase(mm.begin() + j);
                    break;
                }

            }
        }
        ++answer;
    }
    cout << answer;
    return 0;

    /*
4
11 14 16 20
4
15 15 17 18

4
1 1 1 20
4
15 15 17 18

4
2 5 8 12
10
1 2 3 4 5 6 7 8 9 10

3
1 1 2
5
1 1 2 2 2

    */

}