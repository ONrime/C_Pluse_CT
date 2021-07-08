#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution30(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    /*for (auto it = A.begin(); it < A.end(); it++) {
        cout << " " << *it << endl;
    }
    for (auto it = B.begin(); it < B.end(); it++) {
        cout << " " << *it << endl;
    }*/
    for (int i = 0; i < A.size(); i++) {
        answer += A[i] * B[(B.size() - 1) - i];
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    cout << "answer: " << answer << endl;



    return answer;
}

/*int main()
{
    solution30({ 1, 4, 2 }, { 5, 4, 4 }); // 29
    solution30({ 1, 2 }, { 3, 4 }); // 10
}*/

/*

최솟값 만들기

*/