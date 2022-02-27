#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/* 시간 관리
*/

bool cmp(pair<int, int>& left, pair<int, int>& right)
{
    if (left.second == right.second) return left.first > right.first;
    return left.second > right.second;
}

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int answer = 10000000;
    int n;
    vector<pair<int, int>> ts;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int input_t;
        int input_s;
        cin >> input_t;
        cin >> input_s;
        ts.push_back(make_pair(input_t, input_s));
    }
    sort(ts.begin(), ts.end(), cmp);

    //answer = ts[0].second - ts[0].first;

    int temp = 10000000;
    for (int i = 0; i < n; i++)
    {
        //cout << "ts: " << ts[i].first << " " << ts[i].second << endl;

        if (answer < ts[i].second)
        {
            ts[i].second = answer;
        }
        answer = ts[i].second - ts[i].first;
        /*if (temp < 0)
        {
            cout << -1;
            return 0;
        }*/



    }

    /*
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp += ts[i].first;
        if (temp == ts[i].second)
        {
            answer = 0;
        }
        else if (temp > ts[i].second)
        {
            cout << -1;
            return 0;
        }
    }*/
    cout << answer;
    return 0;
}

/*
4
3 4
1 4
5 17
2 20
0
*/