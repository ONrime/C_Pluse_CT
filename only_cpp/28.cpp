#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*

Å¸°Ù ³Ñ¹ö

*/

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