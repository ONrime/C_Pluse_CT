#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 신입 사원
* 탐욕 알고리즘
* 정렬
* 기준에 따른 최적해
* 최적해 판단
*/
bool cmp(pair<int, int>& left, pair<int, int>& right)
{
    return left.first < right.first;
}

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t, n;
    int answer[20];

    cin >> t;
    
	

    for (int i = 0; i < t; i++)
    {
        vector<pair<int, int>> h;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int s, m;
            cin >> s;
            cin >> m;

            h.push_back(make_pair(s, m));
        }
        sort(h.begin(), h.end(), cmp);

        // 정렬 후 모습
        cout << endl;
        for (int j = 0; j < n; j++)
        {
            cout << h[j].first << " " << h[j].second << endl;
        }
        cout << endl;

        pair<int, int> best = make_pair(h[0].first, h[0].second);
        answer[i] = 1;
        for (int j = 0; j < n; j++)
        {
            if (best.second > h[j].second)
            {
                best.second = h[j].second;
                answer[i]++;
            }
        }
    }

    for (int i = 0; i < t; i++)
    {
        cout << answer[i] << endl;
    }
    

	return 0;
}