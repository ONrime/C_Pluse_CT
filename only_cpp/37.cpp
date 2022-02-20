#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// Á¤¼ö »ï°¢Çü

int solution_35_1(vector<vector<int>> triangle) {
    int answer = 0;

    vector<vector<int>> temp(triangle.size(), vector<int>(triangle.size()));
    temp[0][0] = triangle[0][0];

    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if(j == 0)
            {
                temp[i][j] = temp[i - 1][j] + triangle[i][j];
                //cout << "temp0: " << temp[i][j] << endl;
            }
            else if (j == triangle[i].size() - 1)
            {
                temp[i][j] = temp[i - 1][j - 1] + triangle[i][j];
                //cout << "temp_i: " << temp[i][j] << endl;
            }
            else 
            {
                temp[i][j] = max(temp[i - 1][j] + triangle[i][j], temp[i - 1][j - 1] + triangle[i][j]);
                //cout << "temp__: " << temp[i][j] << endl;
            }

            if (i == triangle.size() - 1)
            {
                answer = max(temp[i][j], answer);
            }
        }
        
    }

    cout << "answer: " << answer;
    return answer;
}

/*int main()
{
    solution_35_1({ {7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}}); // 30
}*/
