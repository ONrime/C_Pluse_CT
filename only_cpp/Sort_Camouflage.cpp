#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, int> cloths_map;
    for (auto dex : clothes) {
        if (cloths_map.end() == cloths_map.find(dex[1])) {
            cloths_map.insert(make_pair(dex[1], 1));
        }
        else {
            cloths_map[dex[1]] += 1;
        }
    }
    unordered_map<string, int>::iterator it;
    for (it = cloths_map.begin(); it != cloths_map.end(); it++) {
        answer *= it->second + 1;
    }

    answer -= 1;
    return answer;
}

/*int main()
{
    cout << "solution: " << solution({ {"crowmask", "face"},{"bluesunglasses", "face"},{"smoky_makeup", "face"} }) << "\n";
    cout << "solution: " << solution({ {"yellowhat", "headgear"}, { "bluesunglasses", "eyewear" }, { "green_turban", "headgear" }
        , {"crowmask", "face"},{"bluesunglasses", "face"},{"smoky_makeup", "face"} }) << "\n";
}*/

/*

����
���� ����
�����̵��� ���� �ٸ� ���� �����Ͽ� �Ծ� �ڽ��� �����մϴ�.

���� ��� �����̰� ���� ���� �Ʒ��� ���� ���� �����̰� ���׶� �Ȱ�, �� ��Ʈ, �Ķ��� Ƽ������ �Ծ��ٸ� �������� û������ �߰��� �԰ų� ���׶� �Ȱ� ��� ���� ���۶󽺸� �����ϰų� �ؾ� �մϴ�.

����	�̸�
��	���׶� �Ȱ�, ���� ���۶�
����	�Ķ��� Ƽ����
����	û����
�ѿ�	�� ��Ʈ
�����̰� ���� �ǻ���� ��� 2���� �迭 clothes�� �־��� �� ���� �ٸ� ���� ������ ���� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
clothes�� �� ���� [�ǻ��� �̸�, �ǻ��� ����]�� �̷���� �ֽ��ϴ�.
�����̰� ���� �ǻ��� ���� 1�� �̻� 30�� �����Դϴ�.
���� �̸��� ���� �ǻ��� �������� �ʽ��ϴ�.
clothes�� ��� ���Ҵ� ���ڿ��� �̷���� �ֽ��ϴ�.
��� ���ڿ��� ���̴� 1 �̻� 20 ������ �ڿ����̰� ���ĺ� �ҹ��� �Ǵ� '_' �θ� �̷���� �ֽ��ϴ�.
�����̴� �Ϸ翡 �ּ� �� ���� �ǻ��� �Խ��ϴ�.
����� ��
clothes	return
[["yellowhat", "headgear"], ["bluesunglasses", "eyewear"], ["green_turban", "headgear"]]	5
[["crowmask", "face"], ["bluesunglasses", "face"], ["smoky_makeup", "face"]]	3

*/