#include <iostream>
#include <string>

using namespace std;

/* ��
* �ڸ��� �� ���� �̴�.
* ���� �ڸ����� 8�� �����ϸ� ī��Ʈ �Ѵ�.
*/

/*int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string l, r;
    int answer = 0;

    cin >> l;
    cin >> r;

    // �ڸ��� ��
    if (l.size() != r.size())
    {
        cout << 0 << endl;
        return 0;
    }

    //if()
    string::iterator l_it = l.begin();
    string::iterator r_it = r.begin();
    while ((l_it != l.end() && r_it != r.end()))
    {// && l_it != l.end() - 1
        // ���ڸ��� �ٸ��ٸ�
        if (*(l_it) != *(r_it))
        {
            cout << answer << endl;
            return 0;
        }
        else
        {
            if (*(l_it) == '8')
            { // ���� ���ڰ� 8�̸�
                ++answer;
            }
        }
        //(*(l_it) == '8' && *(r_it) == '8')

        l_it++;
        r_it++;
    }

    cout << answer << endl;
    return 0;
}*/

/*int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int l, r;
    int answer = 0;

    cin >> l;
    cin >> r;

    while (l != 0)
    {
        // cout << "l: " << l % 10 << " r: " << r % 10 << endl;
         //cout << "l: " << l / 10 << " r: " << r / 10 << endl;
        if (l % 10 == r % 10)
        {
            if (l % 10 == 8) ++answer;
        }
        else
        {
            answer = 0;
        }
        l /= 10;
        r /= 10;
    }

    cout << answer << endl;
    return 0;
}*/

/*int find_8(int num)
{
    int count = 0;
    while (true)
    {
        int temp = num % 10;
        if (temp == 8) ++count;

        num = num / 10;
        if (num == 0) break;
    }
    return count;
}

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int l, r;
    int answer = 2000000000;

    cin >> l;
    cin >> r;

    // ���۰� �� ��
    int l_count = find_8(l);
    int r_count = find_8(r);

    //cout << l_count << endl;
    //cout << r_count << endl;

    if (l_count <= r_count)
    {
        answer = l_count;
    }
    else
    {
        answer = r_count;
    }
    //l_count >= r_count ? answer = l_count | answer = r_count;

    if (answer <= 0)
    {
        cout << 0 << endl;
        return 0;
    }
    // ���� ��
    for (int i = l + 1; i < r; i++)
    {
        int count = find_8(i);
        if (answer > count) answer = count;

        if (count == 0)
        {
            break;
        }
    }

    cout << answer << endl;
    return 0;
}*/
