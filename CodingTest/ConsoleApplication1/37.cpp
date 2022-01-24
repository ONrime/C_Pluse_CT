#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

struct PointInfo 
{ 
    int index = 0;
    int base = 0;
    int link = 0;
    float match = 0.0f;
    vector<string> connect;
};

string to_down(string a)
{
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    return a;
}

int solution_37_4(string word, vector<string> pages)
{
    int answer = 0;

    sort(pages.begin(), pages.end());
    int start = 0;
    unordered_map<string, PointInfo> pages_hash;
    for (int i = 0; i < pages.size(); i++)
    {
        start = pages[i].find("content=\"https://", 0);
        string temp = "";
        int a = 9;
        while (temp == "" || temp.back() != '\"') temp.push_back(pages[i][start + a++]);
        temp.pop_back();
        if (pages_hash.end() == pages_hash.find(temp))
        { // �ߺ��� ���� ��
            PointInfo empty_point;
            empty_point.index = i;
            pages_hash.insert(make_pair(temp, empty_point));
        }
        //cout << "ij: " << i << " " << start << " " << pages[i][start + 9] << " " << temp << endl;
        cout << "ij: " << i << " " << start << " " << pages[i][start + 9] << " " << (*pages_hash.begin()).first << endl;
    }

    auto iter = pages_hash.begin();
    for (int i = 0; i < pages_hash.size(); i++)
    {
        start = pages[i].find("<body>", 0) + 7;
        string body_str(pages[i].begin() + start, pages[i].end());
        cout << "pages_hash: " << (*iter).first << endl;

        string temp;
        for (int j = 0; j < body_str.size(); j++)
        {
            if (isalpha(body_str[j]))
            {
                temp.push_back(body_str[j]);
            }
            else {
                if (!temp.empty())
                {
                    if (temp == "href")
                    {
                        (*(iter)).second.link += 1;
                        int end_www = (body_str.find("\"", j + 2));
                        string aa = string(body_str.begin() + j + 2, body_str.begin() + end_www);
                        (*(iter)).second.connect.push_back(aa);
                        j = end_www;
                        //cout << "aa: " << aa << endl;
                    }
                    else if (to_down(word) == to_down(temp)) // ��, �ҹ��� �����ϰ� ��
                    {
                        (*(iter)).second.base += 1;
                        //cout << "temp2: " << temp2 << endl;
                    }
                    temp.clear();
                }
            }
            
        }
        (*(iter)).second.match += (*(iter)).second.base;
        iter++;
    }
    //cout << "test: " << (*(pages_hash.begin())).second.base << endl;
    iter = pages_hash.begin();
    for (int i = 0; i < pages_hash.size(); i++)
    {
        //cout << "connect.size: " << (*(iter)).second.connect.size() << endl;

        for (int i = 0; i < (*(iter)).second.connect.size(); i++)
        {
            auto find_iter = pages_hash.find((*(iter)).second.connect[i]);
            if (pages_hash.end() != find_iter)
            {
                cout << "connect.: " << (*(iter)).second.connect[i] << endl;
                (*find_iter).second.match += (float)(*iter).second.base / (float)(*iter).second.link;
                cout << "connect.. match: " << (*find_iter).first << endl;
                cout << "connect.. match: " << (*find_iter).second.match << endl;
                cout << "connect.. base: " << (float)(*iter).second.base << endl;
            }
        }
        iter++;
    }

    int max_match = 0;
    int max_i = 0;
    for (auto final_iter = pages_hash.begin(); final_iter != pages_hash.end(); final_iter++)
    {
        cout << "match: " << (*final_iter).second.match << endl;
        if (max_match < (*final_iter).second.match) 
        {
            max_match = (*final_iter).second.match;
            answer = max_i;
        }
        max_i++;
    }

    cout << "answer: " << answer << endl;
    return answer;
}

/*int main()
{
    solution_37_4("blind", { "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>" });
    //0
    solution_37_4("Muzi", { "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>" });
    //1
}*/


/*


��Ī����

������ ���б� �������� �������� ��巿�ϸ� ��Ű�� �׿� �а������ �������� ���, īī���� �Ի��ϰ� �Ǿ���.
��ҿ� �����־��ϴ� �˻��� ��ħ ����� �߻��Ͽ�, �˻��������� ���Ե� �� �־���, ����� ù ������Ʈ�� �ð� �Ǿ���.
�� ������Ʈ�� �˻�� ���� �� �´� ���������� �����ֱ� ���� �Ʒ��� ���� ��Ģ���� �˻�� ���� ���������� ��Ī������ ��� �ϴ� ���̾���.

n���� �� ���̿� �ٸ��� �Ǽ��ϴ� ���(costs)�� �־��� ��, �ּ��� ������� ��� ���� ���� ���� �����ϵ��� ���� �� �ʿ��� �ּ� ����� return �ϵ��� solution�� �ϼ��ϼ���.

�ٸ��� ���� �� �ǳʴ���, ������ ���� ������ ���� �����ϴٰ� ���ϴ�. ���� ��� A ���� B �� ���̿� �ٸ��� �ְ�, B ���� C �� ���̿� �ٸ��� ������ A ���� C ���� ���� ���� �����մϴ�.
*/

/*
int solution_37_1(string word, vector<string> pages) {
    int answer = 0;

    int start = 0;
    unordered_map<string, unordered_map<string, int>> pages_hash;
    for (int i = 0; i < pages.size(); i++)
    {
        start = pages[i].find("content=\"https://", 0);
        string temp = "";
        int a = 9;
        while (temp == "" || temp.back() != '\"') temp.push_back(pages[i][start + a++]);
        temp.pop_back();
        if (pages_hash.end() == pages_hash.find(temp))
        { // �ߺ��� ���� ��
            unordered_map<string, int> temp_map;
            vector<string> empty;
            temp_map.insert(make_pair("base", 0));
            temp_map.insert(make_pair("link", 0));
            temp_map.insert(make_pair("match", 0));
            pages_hash.insert(make_pair(temp, temp_map));
        }
        cout << "ij: " << i << " " << start << " " << pages[i][start + 9] << " " << temp << endl;
    }
    cout << "test: " << (*((*pages_hash.begin()).second).find("link")).second << endl;
    for (int i = 0; i < 1; i++)
    {
        auto iter = pages_hash.begin();
        start = pages[i].find("<body>", 0) + 7;
        //int end = pages[i].find("</body>", start);
        string xx(pages[i].begin() + start, pages[i].end());
        //cout << "xx: " << xx << endl;
        istringstream ss(xx);
        string temp;
        while (getline(ss, temp, ' ')) {
            cout << temp << " ";
            if (_stricmp(temp.c_str(), word.c_str()) == 0) // ��, �ҹ��� �����ϰ� ��
            {
                (*((*(iter)).second).find("base")).second += 1;
            }
            string aa;
            if (temp.size() > 4 && string(temp.begin(), temp.begin() + 4) == "href")
            {
                (*((*(iter)).second).find("link")).second += 1;
                //cout << endl << endl;
                aa = string(temp.begin() + 6, temp.end() - 2);
                //cout << "aa: " << aa << endl;
            }
            if (strcmp("<a href=\"", temp.c_str()));

        }
        (*((*(iter)).second).find("match")).second += (*((*(iter)).second).find("base")).second;
        iter++;
    }
    cout << "test: " << (*((*pages_hash.begin()).second).find("base")).second << endl;
    //if(s2.find("content=", 31) != string::npos)
    string text1 = "\n<a href=\"https://b.com\">";
    string text2 = "Song";
    //cout << "test2: " << text1.find(text2, 0) << endl;
    //cout << "test3: " << text1.compare(text2) << endl;
    //cout << "test4: " << strcmp("<a href=\"", text1.c_str()) << endl;
    cout << "test5: " << text1[1] << endl;
    //stricmp("blind", "blind");;
    //if (_stricmp(text1.c_str(), text2.c_str()) == 0)  cout << "strings: text1 and text2 match." << endl;
    cout << "answer: " << answer << endl;
    return answer;
}
*/