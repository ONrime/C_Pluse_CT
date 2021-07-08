#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <map>

using namespace std;

bool compare_music(int i, int j) {
    return j < i;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
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

/*int main()
{
    solution({ "classic", "pop", "classic", "classic", "pop" }, { 500, 600, 150, 800, 2500 }); // 4 1 3 0
    solution({ "classic", "pop", "classic", "classic", "pop", "oldpop" }, { 500, 600, 150, 800, 2500, 50 });
    solution({ "classic", "pop", "classic", "classic", "pop", "oldpop", "clu" }, { 500, 600, 150, 800, 2500, 50, 3000 });
    solution({ "classic","classic","classic","classic","pop" }, { 500,150,800,800,2500 });
    solution({ "classic", "pop", "classic", "pop", "classic", "classic" }, { 400, 600, 150, 600, 500, 500 });
    solution({ "pop", "pop", "pop", "rap", "rap" }, { 45, 50, 40, 60, 70 });
 }*/

/*

º£½ºÆ®¾Ù¹ü

*/