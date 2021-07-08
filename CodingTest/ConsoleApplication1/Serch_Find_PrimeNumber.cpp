#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;
// 조합
/*void combination(vector<char>& combi, vector<int>& out, string numbers, int length, int current_len, int i) {
    //cout << "combination: " << endl; // 3
    if (length == 0) {
        string out_num;
        for (int i = 0; i < combi.size(); i++) {
            out_num += combi[i];
        }
        cout << "out_num: " << out_num << endl;
        cout << "out_num: " << stoi(out_num) << endl;
        out.push_back(stoi(out_num));
    }else if (current_len == combi.size()) { 
        return; 
    }else {
        combi[i] = numbers[current_len];
        cout << "numbers[current_len]: " << numbers[current_len] << endl;
        combination(combi, out, numbers, length - 1, current_len + 1, i + 1);
        combination(combi, out, numbers, length, current_len + 1, i);
    }
}

void combination_overlap(vector<char>& combi, vector<int>& out, string numbers, int length, int current_len, int i, int back) {

    if (current_len == length ) {
        string out_num;
        for (int k = 0; k < length; k++) {
            out_num += combi[k];
        }
        //cout << "out_num: " << stoi(out_num) << endl;
        out.push_back(stoi(out_num));
        return;
    }
    for (int j = 0; j < numbers.size(); j++) {
        int cn = current_len;
        if (back != j) {
            combi[current_len] = numbers[j];
            cn++;
           // cout << "numbers[current_len]: " << numbers[j] << endl;
            combination_overlap(combi, out, numbers, length, current_len + 1, j, j);

        }
        
        
        
    }

}

bool prime_number_check(int num) {
    if (num < 2) { return false; }
    int sq_num = (int)sqrt(num);
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> num;
    vector<int> prime_num;

    for (int i = 1; i < numbers.size()+1; i++) {
        vector<char> combi(i);
        combination_overlap(combi, num, numbers, i, 0, 0, -1);
    }
    cout << "num: ";

    sort(num.begin(), num.end());

    for (auto it = num.begin(); it != num.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "prime_number: ";
    for (int i = 0; i < num.size(); i++) {
        if (prime_number_check(num[i])) {
            if (prime_num.size() == 0 || num[i] != prime_num.back()) {
                prime_num.push_back(num[i]);
                answer++;
                cout << num[i] << " ";
            }
            
        }
    }
    cout << endl;
    

    
    return answer;
}

int solution2(string numbers) {
    int answer = 0;
    vector<int> num;
    vector<int> num2;
    vector<int> prime_num;
    vector<int> check;

    for (int i = 0; i < numbers.size(); i++) {
        num.push_back(numbers[i] - '0');
        check.push_back(0);
    }
    cout << "num: ";
    for (auto it = num.begin(); it != num.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    sort(num.begin(), num.end());

    for (int i = 0; i < numbers.size(); i++) {
        check[i] = 1;
        int a = check[i];
        do {
            string sum;
            for (int j = 0; j < check.size(); j++) {
                if (check[j] == 1) {
                    sum += to_string(num[j]);
                    cout << "num3: "<< num[j] <<endl;
                }
            }
            num2.push_back(stoi(sum));
        } while (next_permutation(num.begin(), num.end()));
    }
    sort(num2.begin(), num2.end());
    num2.erase(unique(num2.begin(), num2.end()), num2.end());

    cout << "num2: ";
    for (auto it = num2.begin(); it != num2.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "prime_number: ";
    for (int i = 0; i < num2.size(); i++) {
        if (prime_number_check(num2[i])) {
            if (prime_num.size() == 0 || num2[i] != prime_num.back()) {
                prime_num.push_back(num2[i]);
                answer++;
                cout << num2[i] << " ";
            }

        }
    }
    cout << endl;



    return answer;
}*/

/*int main()
{
    cout << "answer: " << solution2("17") << endl; // 3
    //cout << "answer: " << solution2("011") << endl; // 2
    //cout << "answer: " << solution2("333") << endl; // 2
    //cout << "answer: " << solution2("1234") << endl; // 2
}*/

/*

소수 찾기

*/