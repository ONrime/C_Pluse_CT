#include <iostream>
#include <string>

using namespace std;

/* 성 지키기
*/


int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int x = 0, y = 0;
    string castle;

    cin >> x;
    cin >> y;

    int x_count = 0;
    int y_count = 0;

    string temp(y, '.');

    for (int i = 0; i < x; i++)
    {
        cin >> castle;

        int x_cut = x_count;
        for (int j = 0; j < y; j++)
        {
            if (castle[j] == 'X')
            {
                if (temp[j] != castle[j])
                {
                    temp[j] = castle[j];
                    ++y_count;
                }
                if (x_count <= x_cut) ++x_count;
            }
        }
    }
    cout << ((x - x_count) >= (y - y_count) ? (x - x_count) : (y - y_count)) << endl;

    return 0;
}