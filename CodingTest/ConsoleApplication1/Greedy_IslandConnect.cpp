#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp_costs(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int get_parent(int bridge, vector<int>& parents) {
    if (parents[bridge] == bridge) { return bridge; };
    return get_parent(parents[bridge], parents);
}

int union_bridge(vector<int>bridges, vector<int>&parents) {
    int bridge1 = get_parent(bridges[0], parents);
    int bridge2 = get_parent(bridges[1], parents);
    if (bridge1 != bridge2) {
        if (bridge1 < bridge2) {
            parents[bridge2] = bridge1;
        }
        else {
            parents[bridge1] = bridge2;
        }
        return bridges[2];
    }
    else {
        return 0;
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int>parents;
    for (int i = 0; i < n; i++) {
        parents.push_back(i);
    }
    sort(costs.begin(), costs.end(), comp_costs);
    /*for (int i = 0; i < costs.size(); i++) {
        cout << "costs[" << i << "]: ";
        for (int j = 0; j < costs[i].size(); j++) {
            cout << costs[i][j] << " ";
        }
        cout << endl;
    }*/

    int count = 0;
    cout << "h: ";
    for (int i = 0; i < costs.size(); i++) {
        int h= union_bridge(costs[i], parents);
        cout << h << " ";
        answer += h;
        if (h != 0) { count++; }
        if (count == n - 1) break;
    }
    cout << endl;
    return answer;
}
/*int main()
{
    //cout << "answer: " << solution(4, { {0, 1, 1}, {0, 2, 2}, {1,2,5}, {1, 3, 1}, {2, 3 ,8} }) << "\n"; // 4
    //cout << "answer: " << solution(6, { {0, 1, 5}, {0, 3, 2}, {0, 4, 3}, {1, 4, 1}, {3, 4, 10}, {1, 2, 2}, {2, 5, 3},{4, 5, 4} }) << "\n"; // 11
    cout << "answer: " << solution(5, { {0, 1, 5}, {1, 2, 3}, {2, 3, 3}, {3, 1, 2}, {3, 0, 4}, {2, 4, 6}, {4, 0, 7} }) << "\n"; // 15
}*/

/*

�� �����ϱ�

���� ����
n���� �� ���̿� �ٸ��� �Ǽ��ϴ� ���(costs)�� �־��� ��, �ּ��� ������� ��� ���� ���� ���� �����ϵ��� ���� �� �ʿ��� �ּ� ����� return �ϵ��� solution�� �ϼ��ϼ���.

�ٸ��� ���� �� �ǳʴ���, ������ ���� ������ ���� �����ϴٰ� ���ϴ�. ���� ��� A ���� B �� ���̿� �ٸ��� �ְ�, B ���� C �� ���̿� �ٸ��� ������ A ���� C ���� ���� ���� �����մϴ�.

���ѻ���

���� ���� n�� 1 �̻� 100 �����Դϴ�.
costs�� ���̴� ((n-1) * n) / 2�����Դϴ�.
������ i�� ����, costs[i][0] �� costs[i] [1]���� �ٸ��� ����Ǵ� �� ���� ��ȣ�� ����ְ�, costs[i] [2]���� �� �� ���� �����ϴ� �ٸ��� �Ǽ��� �� ��� ����Դϴ�.
���� ������ �� �� �־����� �ʽ��ϴ�. ���� ������ �ٲ���� ���� ����� ���ϴ�. �� 0�� 1 ���̸� �����ϴ� ����� �־����� ��, 1�� 0�� ����� �־����� �ʽ��ϴ�.
��� �� ������ �ٸ� �Ǽ� ����� �־����� �ʽ��ϴ�. �� ���, �� �� ������ �Ǽ��� �Ұ����� ������ ���ϴ�.
������ �� ���� ���� �־����� �ʽ��ϴ�.
����� ��

n	costs	return
4	[[0,1,1],[0,2,2],[1,2,5],[1,3,1],[2,3,8]]	4
����� �� ����

costs�� �׸����� ǥ���ϸ� ������ ������, �̶� �ʷϻ� ��η� �����ϴ� ���� ���� ���� ������� ��θ� ������ �� �ֵ��� ����� ����Դϴ�.

*/