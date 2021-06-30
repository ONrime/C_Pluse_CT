#include <string>
#include <vector>
#include <iostream>

using namespace std;

void dfs(int num, int target, int c, int sum, int& answer, vector<int>&numbers) {
    if (num == 0) {
        sum = sum + numbers[c];
    }else { sum = sum - numbers[c]; }
    c++;
    if (c == numbers.size()) {
        if (sum == target) answer++;
        return;
    }
    
    for (int i = 0; i < 2; i++) {
        dfs(i, target, c, sum, answer, numbers);
    }
}

int solution27(vector<int> numbers, int target) {
    int answer = 0;
    int count = 0;

    dfs(0, target, count, 0, answer, numbers);
    dfs(1, target, count, 0, answer, numbers);

    cout << "answer: " << answer << endl;
    return answer;
}
/*int main()
{
    solution27({ 1, 1, 1, 1, 1 }, 3); // 5
}*/
/*

타겟 넘버

문제 설명
n개의 음이 아닌 정수가 있습니다. 이 수를 적절히 더하거나 빼서 타겟 넘버를 만들려고 합니다. 예를 들어 [1, 1, 1, 1, 1]로 숫자 3을 만들려면 다음 다섯 방법을 쓸 수 있습니다.

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
사용할 수 있는 숫자가 담긴 배열 numbers, 타겟 넘버 target이 매개변수로 주어질 때 숫자를 적절히 더하고 빼서 타겟 넘버를 만드는 방법의 수를 return 하도록 solution 함수를 작성해주세요.

제한사항
주어지는 숫자의 개수는 2개 이상 20개 이하입니다.
각 숫자는 1 이상 50 이하인 자연수입니다.
타겟 넘버는 1 이상 1000 이하인 자연수입니다.
입출력 예
numbers	target	return
[1, 1, 1, 1, 1]	3	5
입출력 예 설명
문제에 나온 예와 같습니다.

*/