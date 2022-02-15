#include <iostream>
#include <string>

using namespace std;

/* ÆÈ
*/

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string l, r;
    int l_count = 0, r_count = 0;
    int answer = 0;

    cin >> l;
    cin >> r;

    for (int i = 0; i < l.size(); i++)
    {
        if (l[i] == '8') ++l_count;
    }

    for (int i = 0; i < r.size(); i++)
    {
        if (r[i] == '8') ++r_count;
    }

    l_count <= r_count ? answer = l_count : answer = r_count;

    cout << answer << endl;
    return 0;
}