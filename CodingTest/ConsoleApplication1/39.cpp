#include <iostream>
#include <string>

using namespace std;

/* 명령 프롬프트
* ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
* 이 코드는 C와 C++의 표준 stream의 동기화를 끊는 역할을 한다.
* cin과 cout의 속도가 C의 입출력 속도에 비해 떨어지기 때문에 저 코드를 사용해 속도를 높이는 기능으로 사용한다.getchar
* getchar도 주의해서 사용하기
* 참고 https://ip99202.github.io/posts/sync_with_stdio(false)-%EC%93%B8-%EB%95%8C-%EC%A3%BC%EC%9D%98%ED%95%A0-%EC%82%AC%ED%95%AD/
*/

/*int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // 파일 이름의 개수
    int N = 0;
    cin >> N;

    // 바로 전 입력 데이터
    string temp = "";
    // 정답
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