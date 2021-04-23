#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp_routes(vector<int> a, vector<int> b) {
    return a[0] > b[0];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), comp_routes);
    /*for (int i = 0; i < routes.size(); i++) {
        cout << "routes[" << i << "]: ";
        for (int j = 0; j < routes[i].size(); j++) {
            cout << routes[i][j] << " ";
        }
        cout << endl;
    }*/

    int min = routes[0][0];
    for (int i = 1; i < routes.size(); i++) {
        if (min <= routes[i][1]) {
            continue;
        }
        else {
            answer++;
            min = routes[i][0];
        }
    }answer++;

    return answer;
}

/*int main()
{
    cout << "answer: " << solution({ {-20,15}, {-14,-5}, {-18,-13}, {-5,-3} }) << "\n"; // 2
    cout << "answer: " << solution({ {-20, 15}, {-20, -15}, {-14, -5}, {-18, -13}, {-5, -3} }) << "\n"; // 2
    cout << "answer: " << solution({ {-5, -3}, {-4, 0}, {-4, -2}, {-1, 2}, {0, 3}, {1, 5}, {2, 4} }) << "\n";//2
    cout << "answer: " << solution({ {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}, {9, 10}, {10, 11}, {11, 12}, {12, 13}, {13, 14}, {14, 15} }) << "\n";//8
    cout << "answer: " << solution({ {-7, 0}, {-6, -4}, {-5, -3}, {-3, -1}, {-1, 4}, {1, 2}, {3, 4} }) << "\n";//4 
}*/

/*

�ܼ�ī�޶�

���� ����
��ӵ��θ� �̵��ϴ� ��� ������ ��ӵ��θ� �̿��ϸ鼭 �ܼӿ� ī�޶� �� ���� �������� ī�޶� ��ġ�Ϸ��� �մϴ�.

��ӵ��θ� �̵��ϴ� ������ ��� routes�� �Ű������� �־��� ��, ��� ������ �� ���� �ܼӿ� ī�޶� �������� �Ϸ��� �ּ� �� ���� ī�޶� ��ġ�ؾ� �ϴ����� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

���ѻ���

������ ����� 1�� �̻� 10,000�� �����Դϴ�.
routes���� ������ �̵� ��ΰ� ���ԵǾ� ������ routes[i][0]���� i��° ������ ��ӵ��ο� ������ ����, routes[i][1]���� i��° ������ ��ӵ��ο��� ���� ������ ���� �ֽ��ϴ�.
������ ����/���� ������ ī�޶� ��ġ�Ǿ� �־ ī�޶� ���������� �����մϴ�.
������ ���� ����, ���� ������ -30,000 �̻� 30,000 �����Դϴ�.
����� ��

routes	return
[[-20,15], [-14,-5], [-18,-13], [-5,-3]]	2
����� �� ����

-5 ������ ī�޶� ��ġ�ϸ� �� ��°, �� ��° ������ ī�޶� �����ϴ�.

-15 ������ ī�޶� ��ġ�ϸ� ù ��°, �� ��° ������ ī�޶� �����ϴ�.

*/