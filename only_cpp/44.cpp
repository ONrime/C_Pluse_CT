#include <iostream>
#include <string>

using namespace std;

/* Z
* 분할 정복
* 부분으로 나누어서 문제를 해결하자
*/
/*
// 지역 찾기
int find_area(int n, int& r, int& c, int& temp)
{
    temp = 1;
    for (int i = 0; i < n; i++) temp *= 2;

    if ((0 <= r && r <= (temp - 1)) && (0 <= c && c <= (temp - 1)))
    {
        return 1;
    }
    else if ((temp <= r && r <= ((temp + temp) - 1)) && (0 <= c && c <= (temp - 1)))
    {
        r -= temp;
        return 2;
    }
    else if ((0 <= r && r <= (temp - 1)) && (temp <= c && c <= ((temp + temp) - 1)))
    {
        c -= temp;
        return 3;
    }
    else if ((temp <= r && r <= ((temp + temp) - 1)) && (temp <= c && c <= ((temp + temp) - 1)))
    {
        r -= temp;
        c -= temp;
        return 4;
    }
    return 0;
}

// 정확한 위치 찾기
int find_answer(int n, int r, int c)
{
    int temp = 0;
    int area = find_area(n - 1, r, c, temp);
    if (n != 1)
    {
        int two = 0;
        for (int i = 0; i < area - 1; i++)
        {
            two += temp * temp;
        }
        return two + find_answer(n - 1, r, c);
    }
    else
    {
        return area - 1;
    }

    return 0;
}

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, r, c;

    cin >> n;
    cin >> r;
    cin >> c;

    cout << find_answer(n, c, r) << endl;
    return 0;
}
*/