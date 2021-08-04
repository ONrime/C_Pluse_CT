#include <iostream>
#include <string>
#include <vector>
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

*/