#include <iostream>
#include <string>

using namespace std;

/* ��� ������Ʈ
* ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
* �� �ڵ�� C�� C++�� ǥ�� stream�� ����ȭ�� ���� ������ �Ѵ�.
* cin�� cout�� �ӵ��� C�� ����� �ӵ��� ���� �������� ������ �� �ڵ带 ����� �ӵ��� ���̴� ������� ����Ѵ�.getchar
* getchar�� �����ؼ� ����ϱ�
* ���� https://ip99202.github.io/posts/sync_with_stdio(false)-%EC%93%B8-%EB%95%8C-%EC%A3%BC%EC%9D%98%ED%95%A0-%EC%82%AC%ED%95%AD/
*/

/*int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // ���� �̸��� ����
    int N = 0;
    cin >> N;

    // �ٷ� �� �Է� ������
    string temp = "";
    // ����
    string answer = "";

    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;

        if (temp == "")
        {
            answer = input;
        }
        else
        {
            for (int j = 0; j < input.size(); j++)
            {
                if (input[j] != temp[j])
                {
                    answer[j] = '?';
                }
            }
        }
        temp = input;
    }

    cout << answer << endl;
    return 0;
}*/