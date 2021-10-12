#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp_33(vector<int> a, vector<int> b) 
{
    return a[0] > b[0];
}

int find_min(vector<int> distance, int n, vector<bool> check)
{
    int min = 60000, min_index = 0;
    for(int i=0; i< n; i++)
    {
        if (distance[i] < min && !check[i])
        {
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
}

int solution_33_1(int n, vector<vector<int>> edge) {
    int answer = 0;

    //int distance[100];
    vector<int> distance(n, -1);
    vector<bool> check(n, false);
    sort(edge.begin(), edge.end(), cmp_33);
    /*for (int i = 0; i < edge.size(); i++){
        cout << "edge " << i << ": ";
        for (int j = 0; j < 2; j++) {
            cout << edge[i][j];
        }
        cout << endl;
    }*/

    while (edge.back()[0] == 1)
    {
        //const int k = edge.back()[1];
        distance[edge.back()[1]]++;
        edge.pop_back();
        

    }
    distance[0] = 0;
    check[0] = true;
    
    for (int i = 0; i < n-1; i++)
    {
        //distance.push_back();
        int u = find_min(distance, n, check);
        check[i] = true;
        for (int w = 0; w < n; w++)
        {
            if (!check[w] && distance[u] + 1 < distance[w]) 
            {

            }
        }
    }
    

    cout << "answer: " << answer << endl;
    return answer;
}

/*int main()
{
    solution_33_1(6, { {3, 6} , {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2} }); // 3
    //solution_33_1({ 1, 1, 9, 1, 1, 1 }, 0); // 5
    //solution_33_1({ 1, 1, 3, 1, 4 }, 3); // 5
}*/