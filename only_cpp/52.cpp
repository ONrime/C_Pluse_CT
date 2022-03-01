#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/* นุ มู
*/

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string answer = "";
    int n, m;
    vector<string> h;

    cin >> n >> m;
    int all_size = 0;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        all_size += temp.size();
        h.push_back(temp);
    }
    //sort(h.begin(), h.end());

    int b_ = (m - all_size) / (n - 1);
    int p_ = (m - all_size) % (n - 1);

    for (int i = 1; i < n; i++)
    {
        //cout << h[i] << " " << endl;

        int temp = b_;
        if (p_ > 0 && ((h[i][0] >= 97 && h[i][0] <= 122) || n - p_ <= i))
        {
            p_--;
            temp++;
        }
        for (int j = 0; j < temp; j++) h[i - 1].push_back('_');
        answer += h[i - 1];
    }
    answer += h[n - 1];
    cout << answer;
    return 0;
}

/*
world
_world
__world
___world
___John

Hello____world___John____said
Hello___world____John____said
Hello____world____John___said
*/
