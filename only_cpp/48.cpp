#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

/* 단어 수학
* 정렬 중요
* 탐욕 알고리즘
* 욕심을 내야하는 기준을 생각하자 (큰 수를 갈망)
* 나온 횟수와 자리가 중요
*/

/*
3
GCF
ACDEB
CDE

10
ABB
BB
BB
BB
BB
BB
BB
BB
BB
BB
정답값 : 1790
출력값 : 1780
*/

bool cmp(pair<char, int>& left, pair<char, int>& right)
{
    return left.second > right.second;
}

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int answer = 0;
    int n;
    unordered_map<char, int> alpha;
    vector<string> nn;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        nn.push_back(input);

        for (int j = 0; j < input.size(); j++)
        {
            int temp = 1;
            for (int k = 0; k < input.size() - (j + 1); k++) temp *= 10;
            //cout << "temp: " << temp << endl;
            if (alpha.end() == alpha.find(input[j]))
            { // 중복이 없을 때
                alpha.insert(make_pair(input[j], temp));
            }
            else 
            {
                alpha[input[j]] += temp;
            }
        }
    }

    vector<pair<char, int>> alpha_vec(alpha.begin(), alpha.end());
    sort(alpha_vec.begin(), alpha_vec.end(), cmp);

    int count = 9;
    for (auto it = alpha_vec.begin(); it != alpha_vec.end(); it++)
    {
        alpha[it->first] = count;
        count--;
        //cout << "alpha: " << it->first << " " << it->second << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < nn[i].size(); j++)
        {
            nn[i][j] = alpha[nn[i][j]] + '0';
        }
        answer += stoi(nn[i]);
        //cout << nn[i] << endl;
    }

    cout << answer;
    return 0;
}

/*
vector<string> nn;
string temp = "";
int n;

bool cmp(string& left, string& right)
{
    return left.size() > right.size();
}

// 문자 별 큰 순서 구하기
void find_num2(int i, int& j, int count)
{
    if (j + 1 < n)
    {
        int size1 = nn[j + 1].size();
        int size2 = nn[j].size();
        //cout << size1 - (i + 1)<< endl;
        if (size1 >= size2 - i)
        {
            // 내려가서 올라오기
            j++;
            int s = nn[j].size() - (nn[j - 1].size() - i);
            find_num2(s , j, count);
            temp += nn[j][i];
            //cout << temp << endl;
            if (j != 0)
            {
                j--;
            }
        }
        else
        {
            temp += nn[j][i];
            //cout << temp << endl;
        }
    }
    else 
    {
        temp += nn[j][i];
        j--;
        //cout << temp << endl;
    }
    
}

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int answer = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string input_n;
        cin >> input_n;
        nn.push_back(input_n);
    }

    // 단어 크기에서 큰 순서 구하기
    sort(nn.begin(), nn.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        //cout << nn[i] << endl;
    }

    int j = 0;
    
    // 문자 별 큰 순서 구하기
    for (int i = 0; i < nn[0].size(); i++)
    {
        find_num2(i, j, 0);
    }
    //cout << temp << endl;

    unordered_map<char, int> alpha;
    int count = 9;

    for (int i = 0; i < temp.size(); i++)
    {
        if (alpha.end() == alpha.find(temp[i]))
        { // 중복이 없을 때
            alpha.insert(make_pair(temp[i], count));
            count--;
            if (count < 0) break;
            //cout << "count: " << count << endl;
        }
    }

    /*for (auto it = alpha.begin(); it != alpha.end(); it++)
    {
        cout << "alpha: " << it->first << " " << it->second << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < nn[i].size(); k++)
        {
            nn[i][k] = alpha.find(nn[i][k])->second + '0';
        }
        answer += stoi(nn[i]);
        cout << nn[i] << endl;
    }
    cout << answer;
    return 0;
}*/