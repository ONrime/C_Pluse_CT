#include <string>
#include <vector>
#include <queue>
#include <iostream>

/*

�ٸ��� ������ Ʈ��

������� �����ϴ� ť�� ����� Ǯ����.(0�� �����Ƿ� �ٸ��� ä�� �־���.)

*/

using namespace std;

int solution_32_1(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> bridge;
    int i = 0;
    int now_bridge = 0;
    while (i != truck_weights.size()) {
        if (bridge.size() == bridge_length) 
        {
            now_bridge -= bridge.front();
            bridge.pop();
        }
        if (now_bridge + truck_weights[i] <= weight)
        { // �ٸ� ���� ���� Ʈ�� ���԰� ������ �ٸ��� �����ϰ� �Ѵ�.
            now_bridge += truck_weights[i];
            bridge.push(truck_weights[i]);
            i++;
        }
        else
        { // �ٸ��� Ʈ���� ������ �ȵ����� 0�� �־ �ٸ��� ä�� �־���
            bridge.push(0);
        }
        answer++;
    }
    answer += bridge_length;
    cout << "answer: " << answer << endl;
    return answer;
}

/*int main()
{
    solution_32_1(2, 10, { 7, 4, 5, 6 }); // 8
    solution_32_1(100, 100, {10}); // 101
    solution_32_1(100, 100, { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 }); // 110
}*/