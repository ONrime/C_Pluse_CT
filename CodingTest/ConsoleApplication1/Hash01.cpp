#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> participant_Hash;

    for (int i = 0; i < completion.size(); i++) {
        if (participant_Hash.end() == participant_Hash.find(completion[i])) {
            participant_Hash.insert(make_pair(completion[i], 1));
            //std::cout << " participant_Hash: " << participant_Hash.find(completion[i])->first << "\n";
        }
        else {
            participant_Hash[completion[i]] += 1;
        }
    }

    for (int i = 0; i < participant.size(); i++) {
        if (participant_Hash.end() == participant_Hash.find(participant[i])) {
            //std::cout << " participant_Hash++: " << "\n";
            answer = participant[i];
            break;
        }
        else {
            participant_Hash[participant[i]] -= 1;
            if (participant_Hash[participant[i]] < 0) {
                answer = participant[i];
                break;
            }
        }
    }

    return answer;
}

/*int main()
{
    std::cout << "solution: " << solution({ "mislav", "stanko", "mislav", "ana" }, { "stanko", "ana", "mislav" }) << endl;
    std::cout << "solution: " << solution({ "marina", "josipa", "nikola", "vinko", "filipa" }, { "josipa", "filipa", "marina", "nikola" }) << endl;
}*/
/*

완주하지 못한 선수

*/