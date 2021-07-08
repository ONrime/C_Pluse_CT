#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <sstream>
#include <map>

using namespace std;

/*
vector<string> solution23(vector<string> record) {
    vector<string> answer;
    map<string, string> user;

    for (auto iter = record.rbegin(); iter != record.rend(); iter++) {
        //cout << *iter << endl << endl;;
        vector<string> record_s = split(*iter);
        string state;
        string nick_name;

        user[record_s[1]];
        if (user[record_s[1]] == "") { // 처음 (등록 들어올 때)
            //cout << "user: " << record_s[1] << " " << record_s[2] << endl;
            user[record_s[1]] = record_s[2];
            nick_name = user.begin()->second;
            // cout << "find_user: " << record_s[2] << " " << record_s[1] << endl;
        }
        else { // 이미 등록 완료 (나갈 때 들어올 때 바꿀 때)
            nick_name = user[record_s[1]];
        }

        if (record_s[0] == "Change") {
            continue;
        }
        else if (record_s[0] == "Leave") {
            state = "나갔습니다.";
        }
        else {
            state = "들어왔습니다.";

        }
        answer.push_back(nick_name + "님이 " + state);

    }

    reverse(answer.begin(), answer.end());

    cout << "Log" << endl << endl;
    for (auto iter = answer.begin(); iter != answer.end(); iter++) {
        cout << *iter << endl << endl;;
    }
    return answer;
}*/

vector<string> split(string record) {
    vector<string> s;
    char* str = nullptr;
    char* ptr = strtok_s((char*)record.c_str(), " ", &str);
    while (ptr != nullptr)
    {
        s.push_back(ptr);
        //cout << "split: " << ptr << endl;
        ptr = strtok_s(nullptr, " ", &str);
    }
    return s;
}

vector<string> solution24(vector<string> record) {
    vector<string> answer;
    vector<string> state;
    map<string, string> user;
    vector <string> user_id;

    for (auto iter = record.begin(); iter != record.end(); iter++) {
        //cout << *iter << endl << endl;;
        //vector<string> record_s = split(*iter);
        string nick_name;
        string id;

        char* str = nullptr;
        char* ptr = strtok_s((char*)(*iter).c_str(), " ", &str);
        state.push_back(ptr);
        cout << "ptr: " << ptr << endl;

        while (ptr != nullptr)
        {
            if (state.back() == "Enter") {
                state.pop_back();
                state.push_back("님이 들어왔습니다.");
                ptr = strtok_s(nullptr, " ", &str);
                user_id.push_back(ptr);
                id = ptr;
                ptr = strtok_s(nullptr, " ", &str);
                user[id] = ptr;
                cout << "user_id: " << user_id.back() << endl;
            }
            else if (ptr == "Leave") {
                state.pop_back();
                state.push_back("님이 나갔습니다.");
                ptr = strtok_s(nullptr, " ", &str);
                user_id.push_back(ptr);
            }
            else if (ptr == "Change") {
                state.pop_back();
                ptr = strtok_s(nullptr, " ", &str);
                id = ptr;
                ptr = strtok_s(nullptr, " ", &str);
                user[id] = ptr;
                continue;
            }
            
            ptr = nullptr;
        }

        
        
        //answer.push_back(nick_name + "님이 " + state);

    }

    for (int i = 0; i < 5; i++) {
        //state[i];
        string u = user[user_id[i]] + state[i];
        answer.push_back(u); //아이디에 해당하는 닉네임을 붙여줌
    }

    cout << "Log" << endl << endl;
    for (auto iter = answer.begin(); iter != answer.end(); iter++) {
        cout << *iter << endl << endl;;
    }
    return answer;
}

/*vector<string> solution25(vector<string> record) {
    vector <string> answer;
    vector <string> uid; //record에서 아이디만 따로 저장
    map <string, string> nick_Info; //key:아이디 / value:닉네임
    stringstream ss; string action; string id; string nickname;
    for (int i = 0; i < record.size(); i++) {
        ss.str(record[i]);
        ss >> action; //Enter, Leave, Change
        if (action == "Enter") {
            ss >> id;
            ss >> nickname;
            answer.push_back("님이 들어왔습니다.");
            uid.push_back(id);
            nick_Info[id] = nickname;
        }
        else if (action == "Leave") {
            ss >> id;
            answer.push_back("님이 나갔습니다.");
            uid.push_back(id);
        }
        else {
            ss >> id;
            ss >> nickname;
            nick_Info[id] = nickname;
        }
        ss.clear();
    }
    for (int i = 0; i < answer.size(); i++) {
        answer[i] = nick_Info[uid[i]] + answer[i]; //아이디에 해당하는 닉네임을 붙여줌
    }
    cout << "Log" << endl << endl;
    for (auto iter = answer.begin(); iter != answer.end(); iter++) {
        cout << *iter << endl << endl;;
    }
    return answer;
}*/

/*int main()
{
    solution24({ "Enter uid1234 Muzi"
        , "Enter uid4567 Prodo"
        , "Leave uid1234"
        , "Enter uid1234 Prodo"
        , "Change uid4567 Ryan" });
    solution24({ "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan", "Enter uid1254 Prodokk" });
}*/

/*

오픈채팅방

*/