#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
완주하지 못한 선수
문제에서 (completion의 길이는 participant의 길이보다 1 작습니다.)라고 하는데 이 말은 완주 못하는 사람은 1명이라는 거다.

순서와 관련된 문제라면 정렬을 생각하면 쉽게 풀어진다.
*/

// 해쉬 방법
string solution_1_1(vector<string> participant, vector<string> completion) 
{
    string answer = "";
    unordered_map<string, int> participant_Hash;
    /*
    unordered_map
     map 보다 더 빠른 탐색을 하기 위한 자료구조
     unordered_map은 중복된 데이터를 허용하지 않고 map에 비해 데이터가 많을 시 월등히 좋은 성능을 보인다.
     (unordered_map = O(1), map = O(log n))
     하지만, key가 유사한 데이터가 많을 시 해시 충돌로 인해 성능이 떨어질 수도 있다.
     자동 정렬 X
    */

    for (int i = 0; i < completion.size(); i++) 
    {
        if (participant_Hash.end() == participant_Hash.find(completion[i])) 
        { // 중복이 없을 때
            participant_Hash.insert(make_pair(completion[i], 1));
            //cout << " participant_Hash: " << participant_Hash.find(completion[i])->first << "\n";
        }
        else 
        { // 중복이 있을 때 해쉬안의 내용을 1+
            participant_Hash[completion[i]] += 1;
        }
    }

    for (int i = 0; i < participant.size(); i++) {
        if (participant_Hash.end() == participant_Hash.find(participant[i])) 
        {
            //cout << " participant_Hash++: " << "\n";
            answer = participant[i];
            break;
        }
        else 
        {
            participant_Hash[participant[i]] -= 1;

            if (participant_Hash[participant[i]] < 0) 
            { // 이름 중복이 있다면 0이하일떄 그 사람이 완주를 못 했다는 말이 된다.
                answer = participant[i];
                break;
            }
        }
    }

    return answer;
}

// 정렬 방법
string solution_1_2(vector<string> participant, vector<string> completion) 
{
    string answer = "";

    // 두 벡터 정렬하기
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int i = 0; i < participant.size(); i++) 
    {
        if (completion.size() <= i || participant[i] != completion[i]) 
        { // 만약 완주자 목록 크기보다 i가 크면 or 정렬한 선수 목록과 완주자 목록이 다르면
            answer = participant[i];
            break;
        }
    }

    return answer;
}

/*int main()
{
    cout << "solution: " << solution_1_2({ "leo", "kiki", "eden" }, { "eden", "kiki" }) << endl; // leo
    cout << "solution: " << solution_1_2({ "mislav", "stanko", "mislav", "ana" }, { "stanko", "ana", "mislav" }) << endl; // mislav
    cout << "solution: " << solution_1_1({ "marina", "josipa", "nikola", "vinko", "filipa" }, { "josipa", "filipa", "marina", "nikola" }) << endl; // vinko
}*/