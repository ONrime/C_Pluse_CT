#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*

����

�������� �ϳ��� �����ϴ� ����
 �������� +1�ϰ� �� ���Ѱ�(���⼭�� �ƹ��͵� �� �Դ� ���� ���� ���ϴ� -1�� �ѰŴ�.)

��Ʈ��ŷ ����� ���������� ȿ���� ����.

*/

int solution_3_1(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, int> cloths_map; // �� ������(ex: headgear)�� Ű�� �����. 
    for (auto temp : clothes)
    {
        if (cloths_map.end() == cloths_map.find(temp[1]))
        { // �ߺ��Ȱ� ���ٸ�, dex[1] == clothes�� �� ����(ex: headgear)
            cloths_map.insert(make_pair(temp[1], 1));
        }
        else 
        { // clothes�� �� ������ ������ ����+1
            cloths_map[temp[1]] += 1;
        }
    }
    unordered_map<string, int>::iterator it;
    for (it = cloths_map.begin(); it != cloths_map.end(); it++) 
    {
        answer *= it->second + 1;
    }

    answer -= 1; // �ƹ��͵� �� �Դ� ���� �����Ƿ� 
    return answer;
}

/*int main()
{
    cout << "solution: " << solution_3_1({ {"yellowhat", "headgear"},{"bluesunglasses", "eyewear"},{"green_turban", "headgear"} }) << endl; // 5
    cout << "solution: " << solution_3_1({ {"crowmask", "face"},{"bluesunglasses", "face"},{"smoky_makeup", "face"} }) << endl; // 3
    cout << "solution: " << solution_3_1({ {"yellowhat", "headgear"}, { "bluesunglasses", "eyewear" }, { "green_turban", "headgear" }
        , {"crowmask", "face"},{"bluesunglasses", "face"},{"smoky_makeup", "face"} }) << endl; // 23
}*/