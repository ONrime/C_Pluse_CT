#include <iostream>
#include <string>

using namespace std;

/* 적어도 대부분의 배수
*/

int find(int a, int* num)
{
    int count = 0;
    int answer = 0;
    while (true)
    {
        answer += a;

        for (int j = 0; j < 5; j++)
        {
            if (answer % num[j] == 0)
            {
                ++count;
                if (count > 2) break;
            }
        }
        if (count > 2) break;
        count = 0;
    }
    return answer;
}

/*int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int answer = 10000000;
    int num[5];

     // 숫자 받기
    for (int i = 0; i < 5; i++)
    {
        cin >> num[i];
    }

    for (int i = 0; i < 3; i++)
    {
        int find_num = find(num[i], num);
        if (answer > find_num) answer = find_num;
    }

    cout << answer << endl;
    return 0;
}*/

/*int gcd(int a, int b)
{
    int c = 0;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}*/

/*int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int answer = 10000000;
   // int min = 1000000;
    // 숫자 받기
    for (int i = 0; i < 5; i++)
    {
        cin >> num[i];
        //if (num[i] < min) min = num[i];
        if (i > 0)
        {
            //answer = (num[i - 1] * num[i]) / gcd(num[i - 1], num[i]);
            // cout << answer << endl;
        }
    }
    //cout << answer << endl;

    for (int i = 0; i < 3; i++)
    {
        int find_num = find(num[i]);
        if(answer > find_num) answer = find_num;
    }

    cout << answer << endl;
    //if (find(num[0]) <= find(num[1])) 
   // {
   //     answer = 
    //}
    //find(num[0]);
    //find(num[1]);
   // find(num[4]);

   /* int count = 0;
    int answer = 0;
    while (true)
    {
        answer += min;

        cout << endl;
        cout << "min: " << answer << endl;

        for (int j = 0; j < 5; j++)
        {
            if (answer % num[j] == 0)
            {
                cout << endl;
                cout << "count: " << answer << endl;
                //cout << num[i] << " ";
                ++count;
                if (count > 2) break;
            }
        }
        if (count > 2) break;
        count = 0;
       // break;
    }
    cout << endl;
    cout << answer << endl;
    
    */
    /*for (int i = 0; i < 5; i++)
    {
        cout << num[i] << " ";
    }
   // cout << answer << endl;
    return 0;
}*/