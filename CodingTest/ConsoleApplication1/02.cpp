#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/*

��ȭ��ȣ ���

���ϴ� ������ ������ ���� ��������

*/

bool cmp(string a, string b) { // string ������� ���� (���ڻ� ���� 1~9 ������ ����, �ڸ��� ���� �������� ����)
    if (a.compare(b) > 0) { // a�� ������ -1 b�� ������ 1 ��ȯ
        return false;
    }
    else { return true; }
}

// �ؽ� ���
bool solution_2_1(vector<string> phone_book) 
{
    bool answer = true;
    map<string, int> phonebook_hash; // ��ȣ, ����

    sort(phone_book.begin(), phone_book.end(), cmp); // ���� ���� �� �ڸ��� �������� ����
    for (auto pb : phone_book) 
    { 
        phonebook_hash.insert(make_pair(pb, pb.size())); // ��ȣ�� Ű�� ���̸� �������� ����
    }

    map<string, int>::iterator iter;
    map<string, int>::iterator iter2; // ����
    for (iter = phonebook_hash.begin(); iter != phonebook_hash.end(); iter++) 
    { // ����� ���� �ٷ� ���� ����(++)�� ���ϰ� ������ �����ϸ� �ٷ� false ��ȯ, ������ ���� ���ϸ� ���縦 ++�� �Ѵ�.
        if (iter == phonebook_hash.begin()) 
        {
            iter2 = iter;
            continue;
        }
        if (iter2->first == iter->first.substr(0, iter2->second)) 
        { 
            return false; 
        }
        if (iter2 != phonebook_hash.end()) 
        { 
            iter2++; 
        }
    }
    return answer;
}

// �ؽ� ���� �ϴ� ���
bool solution_2_2(vector<string> phone_book)
{
    bool answer = true;

    sort(phone_book.begin(), phone_book.end(), cmp);

    for (auto iter = phone_book.begin(); iter != phone_book.end()-1; iter++) 
    {
        string temp = *iter;
        iter++;
        if (temp == (*iter).substr(0, temp.size())) 
        {
            return false;
        }
        iter--;
    }

    return answer;
}

/*int main()
{
    cout << "solution: " << solution_2_1({ "119", "97674223", "1195524421" }) << "\n"; // 0
    cout << "solution: " << solution_2_2({ "119", "97674223", "1195524421" }) << "\n"; // 0
    cout << "solution: " << solution_2_1({ "1111", "1111111", "11915524421" }) << "\n"; // 0
    cout << "solution: " << solution_2_2({ "1111", "11915524421", "1111111" }) << "\n"; // 0
    cout << "solution: " << solution_2_2({ "123","456","789" }) << "\n"; // 1
    cout << "solution: " << solution_2_2({ "12","123","1235","567","88" }) << "\n"; // 0
    cout << "solution: " << solution_2_2({ "abc", "aa", "abcd", "aza", "bcda" }) << "\n"; // 0
    cout << "solution: " << solution_2_2({ "112","44","4544" }) << "\n"; // 1
    //cout << "solution: " << false << "\n";
}*/