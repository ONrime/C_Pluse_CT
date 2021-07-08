#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>


using namespace std;


void find_carpet(int& row, int& col, int yellow, int brown) {
    int row2 = row * 2, col2 = col * 2;
    while (row2 + col2 + 4 < brown) {
        row2 = row2 * 2;
        col2 = col2 * 2;
    }
    if (row * col != yellow || row2 + col2 + 4 > brown) {
        if (row > 0 && col > 0) {
            col = col - 1;
            row = yellow / col;
            find_carpet(row, col, yellow, brown);
            return;
        }
    }
    if (row2 + col2 + 4 == brown) {
        row += 2;
        col += 2;
        return;
    }
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int col = (int)sqrt(yellow);
    int row = yellow / col;
    cout << "row: " << row << endl;
    cout << "col: " << col << endl;

    find_carpet(row, col, yellow, brown);

    answer.push_back(row);
    answer.push_back(col);
    cout << "answer: ";
    for (auto it = answer.begin(); it != answer.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return answer;
}

/*int main()
{
    solution(10, 2); // [4, 3]
    solution(8, 1); // [3, 3]
    solution(24, 24); // [8, 6]
    solution(50, 22); // [24, 3]
}*/


/*

Ä«Æê

*/