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
        if (user[record_s[1]] == "") { // ó�� (��� ���� ��)
            //cout << "user: " << record_s[1] << " " << record_s[2] << endl;
            user[record_s[1]] = record_s[2];
            nick_name = user.begin()->second;
            // cout << "find_user: " << record_s[2] << " " << record_s[1] << endl;
        }
        else { // �̹� ��� �Ϸ� (���� �� ���� �� �ٲ� ��)
            nick_name = user[record_s[1]];
        }

        if (record_s[0] == "Change") {
            continue;
        }
        else if (record_s[0] == "Leave") {
            state = "�������ϴ�.";
        }
        else {
            state = "���Խ��ϴ�.";

        }
        answer.push_back(nick_name + "���� " + state);

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
                state.push_back("���� ���Խ��ϴ�.");
                ptr = strtok_s(nullptr, " ", &str);
                user_id.push_back(ptr);
                id = ptr;
                ptr = strtok_s(nullptr, " ", &str);
                user[id] = ptr;
                cout << "user_id: " << user_id.back() << endl;
            }
            else if (ptr == "Leave") {
                state.pop_back();
                state.push_back("���� �������ϴ�.");
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

        
        
        //answer.push_back(nick_name + "���� " + state);

    }

    for (int i = 0; i < 5; i++) {
        //state[i];
        string u = user[user_id[i]] + state[i];
        answer.push_back(u); //���̵� �ش��ϴ� �г����� �ٿ���
    }

    cout << "Log" << endl << endl;
    for (auto iter = answer.begin(); iter != answer.end(); iter++) {
        cout << *iter << endl << endl;;
    }
    return answer;
}

/*vector<string> solution25(vector<string> record) {
    vector <string> answer;
    vector <string> uid; //record���� ���̵� ���� ����
    map <string, string> nick_Info; //key:���̵� / value:�г���
    stringstream ss; string action; string id; string nickname;
    for (int i = 0; i < record.size(); i++) {
        ss.str(record[i]);
        ss >> action; //Enter, Leave, Change
        if (action == "Enter") {
            ss >> id;
            ss >> nickname;
            answer.push_back("���� ���Խ��ϴ�.");
            uid.push_back(id);
            nick_Info[id] = nickname;
        }
        else if (action == "Leave") {
            ss >> id;
            answer.push_back("���� �������ϴ�.");
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
        answer[i] = nick_Info[uid[i]] + answer[i]; //���̵� �ش��ϴ� �г����� �ٿ���
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

����ä�ù�

īī���� ����ä�ù濡���� ģ���� �ƴ� ������ ��ȭ�� �� �� �ִµ�, ���� �г����� �ƴ� ������ �г����� ����Ͽ� ä�ù濡 �� �� �ִ�.

���Ի���� ��ũ��� īī���� ���� ä�ù��� ������ ����� ����, �پ��� ������� ������, ������ ���� ���Ѻ� �� �ִ� ������â�� ������ �ߴ�. ä�ù濡 ������ ������ ���� �޽����� ��µȴ�.

"[�г���]���� ���Խ��ϴ�."

ä�ù濡�� ������ ������ ���� �޽����� ��µȴ�.

"[�г���]���� �������ϴ�."

ä�ù濡�� �г����� �����ϴ� ����� ������ ���� �� �����̴�.

ä�ù��� ���� ��, ���ο� �г������� �ٽ� ����.
ä�ù濡�� �г����� �����Ѵ�.
�г����� ������ ���� ������ ä�ù濡 ��µǾ� �ִ� �޽����� �г��ӵ� ���� ����ȴ�.

���� ���, ä�ù濡 "Muzi"�� "Prodo"��� �г����� ����ϴ� ����� ������� ������ ä�ù濡�� ������ ���� �޽����� ��µȴ�.

"Muzi���� ���Խ��ϴ�."
"Prodo���� ���Խ��ϴ�."

ä�ù濡 �ִ� ����� ������ ä�ù濡�� ������ ���� �޽����� ���´�.

"Muzi���� ���Խ��ϴ�."
"Prodo���� ���Խ��ϴ�."
"Muzi���� �������ϴ�."

Muzi�� ������ �ٽ� ���� ��, Prodo ��� �г������� ���� ��� ������ ä�ù濡 �����ִ� Muzi�� Prodo�� ������ ���� ����ȴ�.

"Prodo���� ���Խ��ϴ�."
"Prodo���� ���Խ��ϴ�."
"Prodo���� �������ϴ�."
"Prodo���� ���Խ��ϴ�."

ä�ù��� �ߺ� �г����� ����ϱ� ������, ���� ä�ù濡�� Prodo��� �г����� ����ϴ� ����� �� ���� �ִ�. ����, ä�ù濡 �� ��°�� ���Դ� Prodo�� Ryan���� �г����� �����ϸ� ä�ù� �޽����� ������ ���� ����ȴ�.

"Prodo���� ���Խ��ϴ�."
"Ryan���� ���Խ��ϴ�."
"Prodo���� �������ϴ�."
"Prodo���� ���Խ��ϴ�."

ä�ù濡 ������ �����ų�, �г����� ������ ����� ��� ���ڿ� �迭 record�� �Ű������� �־��� ��, ��� ����� ó���� ��, ���������� ���� ������ ����� ���� �Ǵ� �޽����� ���ڿ� �迭 ���·� return �ϵ��� solution �Լ��� �ϼ��϶�.

���ѻ���
record�� ������ ���� ���ڿ��� ��� �迭�̸�, ���̴� 1 �̻� 100,000 �����̴�.
������ record�� ��� ���ڿ��� ���� �����̴�.
��� ������ [���� ���̵�]�� �����Ѵ�.
[���� ���̵�] ����ڰ� [�г���]���� ä�ù濡 ���� - "Enter [���� ���̵�] [�г���]" (ex. "Enter uid1234 Muzi")
[���� ���̵�] ����ڰ� ä�ù濡�� ���� - "Leave [���� ���̵�]" (ex. "Leave uid1234")
[���� ���̵�] ����ڰ� �г����� [�г���]���� ���� - "Change [���� ���̵�] [�г���]" (ex. "Change uid1234 Muzi")
ù �ܾ�� Enter, Leave, Change �� �ϳ��̴�.
�� �ܾ�� �������� ���еǾ� ������, ���ĺ� �빮��, �ҹ���, ���ڷθ� �̷�����ִ�.
���� ���̵�� �г����� ���ĺ� �빮��, �ҹ��ڸ� �����Ѵ�.
���� ���̵�� �г����� ���̴� 1 �̻� 10 �����̴�.
ä�ù濡�� ���� ������ �г����� �����ϴ� �� �߸� �� �Է��� �־����� �ʴ´�.
����� ��
record	result
["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]
["Prodo���� ���Խ��ϴ�.", "Ryan���� ���Խ��ϴ�.", "Prodo���� �������ϴ�.", "Prodo���� ���Խ��ϴ�."]
����� �� ����
����� �� #1
������ ����� ����.

*/