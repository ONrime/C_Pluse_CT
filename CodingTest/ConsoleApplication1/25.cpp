#include <string>
#include <vector>
#include <iostream>

using namespace std;



int solution26(string s) {
    int answer = 0;
    string temp;
    string a = s;
    int count = 1;
    int start = 0;
    int less = 100000000;
   // cout << "check: " << (s.size() / 2)+1 << endl;
    for (int i = 1; i < (s.size() / 2) + 1; i++) {
        for (int j = 0; j < s.size() + 1; j += i) {
            if (temp.empty() == true) {
                count = 1;
                start = j;
                temp = s.substr(j, i);
            }
            else {
                if (temp == s.substr(j, i)) {count++;}
                else {
                    if (count != 1) {
                       s.replace(start, (count - 1) * i, to_string(count));
                       j = j - (count*i)+i;
                    }
                    else {j = j - i;}
                    //s.replace(start, (count - 1) * i, to_string(count));
                    //j = j - (count * i) + 1;
                    temp.clear();
                }
            }
        }
        //if (less > s.size()) less = strlen(s.c_str());
        if (less > s.size()) less = s.length();
        cout << "answerd: " << s << endl;
        s = a;
        temp.clear(); 
    }
    if (less == 100000000) less = s.length();
    cout << "answer: " << less << endl;
    return answer;
}
/*int main()
{
    solution26("xxxxxxxxxxyyy"); // 5
    solution26("abcdefghiuop"); // 12
    //solution26("aa  b"); // 5
    //solution26("aaaaaaaaaab"); // 4
    solution26("ababcdcdababcdcd"); // 9
    //solution26("abcdabcd"); // 5
   // solution26("a"); // 1
    solution26("aaaabbbacccccc"); // 7
    solution26("abcabcabcabcdededededede"); // 14
    solution26("abcabcdede"); // 8
    solution26("abababac"); // 7
    solution26("ababacacdd"); // 8
    solution26("ababcdcdababcdcd"); // 9
    //solution26("xababcdcdababcdcd"); // 17
   // solution26("acacacbacacac"); // 9 3acba2cac
   // solution26("acacacacacacbacacacacacac"); // 9 6acba5cac
    //solution26("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"); // 4 100a
    //solution26("zxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"); // 5 
    //solution26("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxz"); // 5 
    solution26("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"); // 5 
}*/
/*

문자열 압축

*/