#include <iostream>
#include <vector>

using namespace std;

/* 물병
*/

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k;
    int answer = 0;
    vector<int> bowl;

    cin >> n;
    cin >> k;

    if (n <= k)
    {
        cout << 0 << endl;
        return 0;
    }

    int cut = n;
    while (1)
    {
        int temp = 1;
        while (temp * 2 < cut) temp *= 2;

        bowl.push_back(temp);
        cut -= temp;

        if ((cut & (cut - 1)) == 0)
        {
            bowl.push_back(cut);
            break;
        }
        if (cut <= 0) break;
    }

    if (bowl.size() > k)
    {
        while (k != bowl.size())
        {
            int back = bowl.back();
            bowl.pop_back();
            answer += (bowl.back() - back);
            bowl.back() *= 2;
        }
    }
    else
    {
        answer = 0;
    }
    cout << answer << endl;
    return 0;
}






//int kk[1001] = {};
/*vector<int> kk;

int find_water(int n, int k, int index)
{
    // 그릇 구하기
    int bowl = 2;
    while (bowl * 2 <= n / k)
    {
        bowl *= 2;
    }
    cout << "bowl: " << bowl << endl;

    kk.push_back(bowl);
    
    if (k % 2 == 0)
    { // 짝수
        for (int i = 0; i < k - 2; i++) kk.back() *= bowl;
        cout << "kk.back(): " << kk.back() << endl;
        index += 1;
    }
    else 
    { // 홀수
        for (int i = 0; i < k - 3; i++) kk.back() *= bowl;
        cout << "kk.back(): " << kk.back() << endl;
        index += 2;
        if (kk.size() > 1) // !kk[index + 1] 초기화 없을 때?
        { // 비교 할 대상이 있을 때
            if (kk.back() > *(kk.rbegin()-1))
            {
                int temp = *(kk.rbegin() - 1);
                *(kk.rbegin() - 1) = kk.back();
                kk.back() = temp;
            }
        }
        kk.push_back(bowl);
        //kk[index + 1] = bowl;
    }
   // kk

    // 나머지
    int temp = n - bowl * k;
    cout << "temp: " << temp << endl;
    cout << "k: " << k << endl;

    find_water(temp, k - 1, index + 2);

    if (temp < 2)
    {

        return bowl - temp;
    }

    return -1;

   /* // 나머지가 존재 할 때
    if (temp < 2)
    {
        return bowl - temp;
    }
    return find_water(temp, k - 1, index + 2);
}*/

/*int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 2;
    for (int i = 0; i < 30; i++)
    {
        t *= 2;
        cout << "2*2: " << t << endl;
    }

    int n, k;
    string castle;
    cout << "dd: " << 7%2 << endl;
    cin >> n;
    cin >> k;

    cout << "find_water: " << find_water(n, k, 0) << endl;
    return 0;
}*/