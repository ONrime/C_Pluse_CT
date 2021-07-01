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
        if (wordCount == 1 && check[i] == false) { // (�ٲٱ�) �ϳ��� �ٸ� ��
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

�ܾ� ��ȯ

���� ����
�� ���� �ܾ� begin, target�� �ܾ��� ���� words�� �ֽ��ϴ�. �Ʒ��� ���� ��Ģ�� �̿��Ͽ� begin���� target���� ��ȯ�ϴ� ���� ª�� ��ȯ ������ ã������ �մϴ�.

1. �� ���� �� ���� ���ĺ��� �ٲ� �� �ֽ��ϴ�.
2. words�� �ִ� �ܾ�θ� ��ȯ�� �� �ֽ��ϴ�.
���� ��� begin�� "hit", target�� "cog", words�� ["hot","dot","dog","lot","log","cog"]��� "hit" -> "hot" -> "dot" -> "dog" -> "cog"�� ���� 4�ܰ踦 ���� ��ȯ�� �� �ֽ��ϴ�.

�� ���� �ܾ� begin, target�� �ܾ��� ���� words�� �Ű������� �־��� ��, �ּ� �� �ܰ��� ������ ���� begin�� target���� ��ȯ�� �� �ִ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
�� �ܾ�� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.
�� �ܾ��� ���̴� 3 �̻� 10 �����̸� ��� �ܾ��� ���̴� �����ϴ�.
words���� 3�� �̻� 50�� ������ �ܾ ������ �ߺ��Ǵ� �ܾ�� �����ϴ�.
begin�� target�� ���� �ʽ��ϴ�.
��ȯ�� �� ���� ��쿡�� 0�� return �մϴ�.
����� ��
begin	target	words	return
"hit"	"cog"	["hot", "dot", "dog", "lot", "log", "cog"]	4
"hit"	"cog"	["hot", "dot", "dog", "lot", "log"]	0
����� �� ����
���� #1
������ ���� ���� �����ϴ�.

���� #2
target�� "cog"�� words �ȿ� ���� ������ ��ȯ�� �� �����ϴ�.

*/