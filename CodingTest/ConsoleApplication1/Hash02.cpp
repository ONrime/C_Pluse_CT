#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> phonebook_hash; // ��ȣ, ����

    sort(phone_book.begin(), phone_book.end());
    for (auto pb : phone_book) {
        phonebook_hash.insert(make_pair(pb, pb.size()));
    }

    unordered_map<string, int>::iterator iter;
    unordered_map<string, int>::iterator iter2; // ����
    for (iter = phonebook_hash.begin(); iter != phonebook_hash.end(); iter++) {
        if (iter == phonebook_hash.begin()) {
            iter2 = iter;
            continue;
        }
        if (iter2->first == iter->first.substr(0, iter2->second)) {
            return false;
        }
        if (iter2 != phonebook_hash.end()) {
            iter2++;
        }
    }
    return answer;
}

/*int main()
{
    std::cout << "solution: " << solution({ "119", "97674223", "1195524421" }) << "\n";
    std::cout << "solution: " << solution({ "123","456","789" }) << "\n";
    std::cout << "solution: " << solution({ "12","123","1235","567","88" }) << "\n";
    std::cout << "solution: " << solution({ "abc", "aa", "abcd", "aza", "bcda" }) << "\n";
}*/

/*

���� ����
��ȭ��ȣ�ο� ���� ��ȭ��ȣ ��, �� ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 �ִ��� Ȯ���Ϸ� �մϴ�.
��ȭ��ȣ�� ������ ���� ���, ������ ��ȭ��ȣ�� �������� ��ȭ��ȣ�� ���λ��Դϴ�.

������ : 119
���ؿ� : 97 674 223
������ : 11 9552 4421
��ȭ��ȣ�ο� ���� ��ȭ��ȣ�� ���� �迭 phone_book �� solution �Լ��� �Ű������� �־��� ��, � ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 ������ false�� �׷��� ������ true�� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���� ����
phone_book�� ���̴� 1 �̻� 1,000,000 �����Դϴ�.
�� ��ȭ��ȣ�� ���̴� 1 �̻� 20 �����Դϴ�.
���� ��ȭ��ȣ�� �ߺ��ؼ� ������� �ʽ��ϴ�.
����� ����
phone_book	return
["119", "97674223", "1195524421"]	false
["123","456","789"]	true
["12","123","1235","567","88"]	false

*/