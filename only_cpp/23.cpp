#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution20(string s)
{
	int answer = -1;
	answer = 0;
	stack<char> s_s;

	while (!s.empty()) {
		if (s_s.empty() || s.back() != s_s.top()) s_s.push(s.back());
		else s_s.pop();
		s.pop_back();
		if (s.empty() && s_s.empty()) answer = 1;
	}

	return answer;
}

/*int main()
{
	cout << "answer: " << solution20("baabaa") << "\n"; // 1
	cout << "answer: " << solution20("cdcd") << "\n"; // 0
}*/


/*

짝지어 제거하기

*/