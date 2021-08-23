#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*

위장

종류별로 하나씩 선택하는 조합
 종류별로 +1하고 다 곱한것(여기서는 아무것도 안 입는 것은 포함 안하니 -1을 한거다.)

백트래킹 방법도 가능하지만 효율이 낮다.

*/

int solution_3_1(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, int> cloths_map; // 옷 종류별(ex: headgear)로 키를 만든다. 
    for (auto temp : clothes)
    {
        if (cloths_map.end() == cloths_map.find(temp[1]))
        { // 중복된게 없다면, dex[1] == clothes의 옷 종류(ex: headgear)
            cloths_map.insert(make_pair(temp[1], 1));
        }
        else 
        { // clothes의 옷 종류가 같으면 내용+1
            cloths_map[temp[1]] += 1;
        }
    }
    unordered_map<string, int>::iterator it;
    for (it = cloths_map.begin(); it != cloths_map.end(); it++) 
    {
        answer *= it->second + 1;
    }

    answer -= 1; // 아무것도 안 입는 경우는 없으므로 
    return answer;
}

/*int main()
{
    cout << "solution: " << solution_3_1({ {"yellowhat", "headgear"},{"bluesunglasses", "eyewear"},{"green_turban", "headgear"} }) << endl; // 5
    cout << "solution: " << solution_3_1({ {"crowmask", "face"},{"bluesunglasses", "face"},{"smoky_makeup", "face"} }) << endl; // 3
    cout << "solution: " << solution_3_1({ {"yellowhat", "headgear"}, { "bluesunglasses", "eyewear" }, { "green_turban", "headgear" }
        , {"crowmask", "face"},{"bluesunglasses", "face"},{"smoky_makeup", "face"} }) << endl; // 23
}*/