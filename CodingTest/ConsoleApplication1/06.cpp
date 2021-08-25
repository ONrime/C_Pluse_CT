#include <string>
#include <vector>
#include <queue>
#include <iostream>

/*

다리를 지나는 트럭

순서대로 진행하는 큐를 만들어 풀었다.(0을 넣으므로 다리를 채워 넣었다.)

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
        { // 다리 무게 보다 트럭 무게가 적으면 다리에 진입하게 한다.
            now_bridge += truck_weights[i];
            bridge.push(truck_weights[i]);
            i++;
        }
        else
        { // 다리에 트럭이 지나면 안되지만 0을 넣어서 다리를 채워 넣었다
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