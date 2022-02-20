#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/*

전화번호 목록

비교하는 문제면 정령을 먼저 생각하자

*/

bool cmp(string a, string b) { // string 순서대로 정렬 (숫자상 순서 1~9 순으로 정렬, 자릿수 작은 기준으로 정렬)
    if (a.compare(b) > 0) { // a가 먼저면 -1 b가 먼저면 1 반환
        return false;
    }
    else { return true; }
}

// 해쉬 방법
bool solution_2_1(vector<string> phone_book) 
{
    bool answer = true;
    map<string, int> phonebook_hash; // 번호, 길이

    sort(phone_book.begin(), phone_book.end(), cmp); // 숫자 순서 및 자릿수 기준으로 정렬
    for (auto pb : phone_book) 
    { 
        phonebook_hash.insert(make_pair(pb, pb.size())); // 번호를 키로 길이를 내용으로 전달
    }

    map<string, int>::iterator iter;
    map<string, int>::iterator iter2; // 과거
    for (iter = phonebook_hash.begin(); iter != phonebook_hash.end(); iter++) 
    { // 현재와 현재 바로 뒤의 내용(++)을 비교하고 조건을 충족하면 바로 false 반환, 조건을 충족 못하면 현재를 ++를 한다.
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

// 해쉬 없이 하는 방법
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