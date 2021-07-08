#include <string>
#include <vector>
#include <iostream>

using namespace std;

void changeWord(string begin, string target, vector<string> words, int& min, int count, bool check[]) {
    if (begin == target && min > count) min = count;
    for (int i = 0; i < words.size(); i++) {
        int wordCount = 0;
        for (int j = 0; j < words[i].size(); j++) {
            if (words[i][j] != begin[j]) wordCount++;
        }
        if (wordCount == 1 && check[i] == false) { // (바꾸기) 하나만 다를 때
            count++;
            check[i] = true;
            changeWord(words[i], target, words, min, count, check);
            check[i] = false;
            count--;
        }
    }
}

int solution29(string begin, string target, vector<string> words) {
    int answer = 50;
    bool check[50] = {false, };
    changeWord(begin, target, words, answer, 0, check);
    if (answer == 50) answer = 0;
    cout << "answer: " << answer << endl;
    return answer;
}

/*int main()
{
    solution29("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}); // 4
    solution29("hit", "cog", {"hot", "dot", "dog", "lot", "log"}); // 0
    solution29("aab", "aaa", {"aac", "aaa"}); // 1
}*/

/*

단어 변환

*/