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

베스트앨범

문제 설명
스트리밍 사이트에서 장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범을 출시하려 합니다. 노래는 고유 번호로 구분하며, 노래를 수록하는 기준은 다음과 같습니다.

속한 노래가 많이 재생된 장르를 먼저 수록합니다.
장르 내에서 많이 재생된 노래를 먼저 수록합니다.
장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.
노래의 장르를 나타내는 문자열 배열 genres와 노래별 재생 횟수를 나타내는 정수 배열 plays가 주어질 때, 베스트 앨범에 들어갈 노래의 고유 번호를 순서대로 return 하도록 solution 함수를 완성하세요.

제한사항
genres[i]는 고유번호가 i인 노래의 장르입니다.
plays[i]는 고유번호가 i인 노래가 재생된 횟수입니다.
genres와 plays의 길이는 같으며, 이는 1 이상 10,000 이하입니다.
장르 종류는 100개 미만입니다.
장르에 속한 곡이 하나라면, 하나의 곡만 선택합니다.
모든 장르는 재생된 횟수가 다릅니다.
입출력 예
genres	plays	return
["classic", "pop", "classic", "classic", "pop"]	[500, 600, 150, 800, 2500]	[4, 1, 3, 0]
입출력 예 설명
classic 장르는 1,450회 재생되었으며, classic 노래는 다음과 같습니다.

고유 번호 3: 800회 재생
고유 번호 0: 500회 재생
고유 번호 2: 150회 재생
pop 장르는 3,100회 재생되었으며, pop 노래는 다음과 같습니다.

고유 번호 4: 2,500회 재생
고유 번호 1: 600회 재생

*/