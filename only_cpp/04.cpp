#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

/*

����Ʈ�ٹ�

map�� Ű������ �����Ѵ�.

*/

bool compare_music(int i, int j) {
    return j < i;
}

vector<int> solution_4_1(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map<string, vector<int>> music_list;
    unordered_map<int, vector<int>> music_num;
    unordered_map<string, int> music_size;
    map<int, string> music_size2;

    for (int i = 0; i < genres.size(); i++) {
        if (music_num.end() == music_num.find(plays[i])) {
            vector<int> num_point = { i };
            music_num.insert(make_pair(plays[i], num_point));
        }
        else {
            music_num.find(plays[i])->second.push_back(i);
        }
        if (music_list.end() == music_list.find(genres[i])) {
            vector<int> zero_point = { plays[i], plays[i] };
            music_list.insert(make_pair(genres[i], zero_point));
        }
        else {
            unordered_map<string, vector<int>>::iterator find_list;
            find_list = music_list.find(genres[i]);
            find_list->second.push_back(plays[i]);
            find_list->second[0] += plays[i];
        }
    }
    unordered_map<string, vector<int>>::iterator it;
    for (it = music_list.begin(); it != music_list.end(); it++) {
        music_size2.insert(make_pair(it->second[0] * -1, it->first));
        sort(it->second.begin(), it->second.end(), compare_music);
    }

    map<int, string>::iterator it5;
    for (it5 = music_size2.begin(); it5 != music_size2.end(); it5++) {
        unordered_map<string, vector<int>>::iterator find_list2;
        find_list2 = music_list.find(it5->second);
        if (find_list2->second.size() > 2) {
            answer.push_back(music_num.find(find_list2->second[1])->second[0]);
            if (find_list2->second[1] == find_list2->second[2]) {
                answer.push_back(music_num.find(find_list2->second[2])->second[1]);
            }
            else {
                answer.push_back(music_num.find(find_list2->second[2])->second[0]);
            }
        }
        else {
            answer.push_back(music_num.find(find_list2->second[1])->second[0]);
        }
    }

    cout << "answer: ";
    for (auto a : answer) {
        cout << a << " ";
    }
    cout << "\n";

    return answer;
}

bool Cmp_Genres(pair<string, int> i, pair<string, int> j) {
    return j.second < i.second;
}

bool Cmp_Plays(pair<int, int> i, pair<int, int> j) {
    return j.second < i.second;
}

vector<int> solution_4_2(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map<string, int> GenresList;
    unordered_map<string, vector<pair<int, int>>> PlaysList;

    for (int i = 0; i < genres.size(); i++) 
    { // ������, �뷡���� ����
        GenresList[genres[i]] += plays[i]; // �������� ������ ������ �����Ѵ�. (���߿� �������� ����)
        PlaysList[genres[i]].push_back(make_pair(i, plays[i])); // �������� �����ϵ� ���� �÷��̼����� �����Ѵ�.
        sort(PlaysList[genres[i]].begin(), PlaysList[genres[i]].end(), Cmp_Plays); 
    }

    vector<pair<string, int>> GenresList_Vec(GenresList.begin(), GenresList.end());
    sort(GenresList_Vec.begin(), GenresList_Vec.end(), Cmp_Genres);

    for (auto iter = GenresList_Vec.begin(); iter != GenresList_Vec.end(); iter++) 
    {
        if (PlaysList.end() != PlaysList.find(iter->first))
        {
            auto iter2 = PlaysList.find(iter->first);
            for (int j = 0; j < 2; j++) // �� � �̾Ƽ� answer�� �ִ´�.
            {
                answer.push_back(iter2->second[j].first);
                if (iter2->second.size() < 2) break; // �� �� �̻��� �ƴ� ��� ������.
            }
        }
    }
    cout << "answer: ";
    for (auto a : answer) {
        cout << a << " ";
    }
    cout << "\n";
    return answer;
}

/*int main()
{
    //solution_4_1({ "classic", "pop", "classic", "classic", "pop" }, { 500, 600, 150, 800, 2500 }); // 4 1 3 0
    solution_4_2({ "classic", "pop", "classic", "classic", "pop" }, { 500, 600, 150, 800, 2500 }); // 4 1 3 0
    solution_4_2({ "classic", "pop", "classic", "classic", "pop", "oldpop" }, { 500, 600, 150, 800, 2500, 50 }); // 4 1 3 0 5
    solution_4_2({ "classic", "pop", "classic", "classic", "pop", "oldpop", "clu" }, { 500, 600, 150, 800, 2500, 50, 3000 }); // 4 1 6 3 0 5
    solution_4_2({ "classic","classic","classic","classic","pop" }, { 500,150,800,800,2500 }); // 4 2 3
    solution_4_2({ "classic", "pop", "classic", "pop", "classic", "classic" }, { 400, 600, 150, 600, 500, 500 }); // 4 5 1 3
    solution_4_2({ "pop", "pop", "pop", "rap", "rap" }, { 45, 50, 40, 60, 70 }); // 1 0 4 3
 }*/
