#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
�������� ���� ����
�������� (completion�� ���̴� participant�� ���̺��� 1 �۽��ϴ�.)��� �ϴµ� �� ���� ���� ���ϴ� ����� 1���̶�� �Ŵ�.

������ ���õ� ������� ������ �����ϸ� ���� Ǯ������.
*/

// �ؽ� ���
string solution_1_1(vector<string> participant, vector<string> completion) 
{
    string answer = "";
    unordered_map<string, int> participant_Hash;
    /*
    unordered_map
     map ���� �� ���� Ž���� �ϱ� ���� �ڷᱸ��
     unordered_map�� �ߺ��� �����͸� ������� �ʰ� map�� ���� �����Ͱ� ���� �� ������ ���� ������ ���δ�.
     (unordered_map = O(1), map = O(log n))
     ������, key�� ������ �����Ͱ� ���� �� �ؽ� �浹�� ���� ������ ������ ���� �ִ�.
     �ڵ� ���� X
    */

    for (int i = 0; i < completion.size(); i++) 
    {
        if (participant_Hash.end() == participant_Hash.find(completion[i])) 
        { // �ߺ��� ���� ��
            participant_Hash.insert(make_pair(completion[i], 1));
            //cout << " participant_Hash: " << participant_Hash.find(completion[i])->first << "\n";
        }
        else 
        { // �ߺ��� ���� �� �ؽ����� ������ 1+
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
            { // �̸� �ߺ��� �ִٸ� 0�����ϋ� �� ����� ���ָ� �� �ߴٴ� ���� �ȴ�.
                answer = participant[i];
                break;
            }
        }
    }

    return answer;
}

// ���� ���
string solution_1_2(vector<string> participant, vector<string> completion) 
{
    string answer = "";

    // �� ���� �����ϱ�
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int i = 0; i < participant.size(); i++) 
    {
        if (completion.size() <= i || participant[i] != completion[i]) 
        { // ���� ������ ��� ũ�⺸�� i�� ũ�� or ������ ���� ��ϰ� ������ ����� �ٸ���
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