#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    if (a.compare(b) > 0) {
        return false;
    }
    else { return true; }
}

bool solution00(vector<string> phone_book) {
    bool answer = true;
    map<string, int> phonebook_hash; // 번호, 길이

    sort(phone_book.begin(), phone_book.end(), cmp);
    for (auto pb : phone_book) { phonebook_hash.insert(make_pair(pb, pb.size())); }

    map<string, int>::iterator iter;
    map<string, int>::iterator iter2; // 과거
    for (iter = phonebook_hash.begin(); iter != phonebook_hash.end(); iter++) {
        if (iter == phonebook_hash.begin()) {
            iter2 = iter;
            continue;
        }
        if (iter2->first == iter->first.substr(0, iter2->second)) { return false; }
        if (iter2 != phonebook_hash.end()) { iter2++; }
    }
    return answer;
}

/*int main()
{
    cout << "solution: " << solution00({ "119", "97674223", "1195524421" }) << "\n";
    cout << "solution: " << solution00({ "1111", "1111111", "11915524421" }) << "\n";
    cout << "solution: " << solution00({ "1111", "11915524421", "1111111" }) << "\n";
    cout << "solution: " << solution00({ "123","456","789" }) << "\n";
    cout << "solution: " << solution00({ "12","123","1235","567","88" }) << "\n";
    cout << "solution: " << solution00({ "abc", "aa", "abcd", "aza", "bcda" }) << "\n";
    cout << "solution: " << solution00({ "112","44","4544" }) << "\n";
    //cout << "solution: " << false << "\n";
}*/

/*

전화번호 목록

문제 설명
전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려 합니다.
전화번호가 다음과 같을 경우, 구조대 전화번호는 영석이의 전화번호의 접두사입니다.

구조대 : 119
박준영 : 97 674 223
지영석 : 11 9552 4421
전화번호부에 적힌 전화번호를 담은 배열 phone_book 이 solution 함수의 매개변수로 주어질 때, 어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를 그렇지 않으면 true를 return 하도록 solution 함수를 작성해주세요.

제한 사항
phone_book의 길이는 1 이상 1,000,000 이하입니다.
각 전화번호의 길이는 1 이상 20 이하입니다.
같은 전화번호가 중복해서 들어있지 않습니다.
입출력 예제
phone_book	return
["119", "97674223", "1195524421"]	false
["123","456","789"]	true
["12","123","1235","567","88"]	false

*/