#include <iostream>

using namespace std;

long long solution21(int w, int h) {
    long long answer = 1;

    int gong = 1;
    long long ww = w;
    long long hh = h;
    while (true) {
        if (w % 3 == 0 && h % 3 == 0) {
            w /= 3;
            h /= 3;
            gong = gong * 3;
        }
        else if (w % 2 == 0 && h % 2 == 0) {
            w /= 2;
            h /= 2;
            gong = gong * 2;
        }
        else {
            break;
        }
    }
    answer = ww * hh - ((ww + hh) - (long long)gong);
    return answer;
}

long long solution22(int w, int h) {
    long long answer = 1;

    int gong = 0;
    long long sum = (long long)w + (long long)h;
    long long multi = (long long)w * (long long)h;
    int temp = 0;

    while (h != 0) {
        temp = w % h;
        w = h;
        h = temp;
    }
    gong = w;

    answer = multi - (sum - gong);
    return answer;
}

/*int main()
{
	cout << "answer: " << solution22(8, 12) << "\n"; // 80
	cout << "answer: " << solution22(3, 4) << "\n"; // 6
}*/
/*

멀쩡한 사각형

문제 설명
가로 길이가 Wcm, 세로 길이가 Hcm인 직사각형 종이가 있습니다. 종이에는 가로, 세로 방향과 평행하게 격자 형태로 선이 그어져 있으며, 모든 격자칸은 1cm x 1cm 크기입니다. 이 종이를 격자 선을 따라 1cm × 1cm의 정사각형으로 잘라 사용할 예정이었는데, 누군가가 이 종이를 대각선 꼭지점 2개를 잇는 방향으로 잘라 놓았습니다. 그러므로 현재 직사각형 종이는 크기가 같은 직각삼각형 2개로 나누어진 상태입니다. 새로운 종이를 구할 수 없는 상태이기 때문에, 이 종이에서 원래 종이의 가로, 세로 방향과 평행하게 1cm × 1cm로 잘라 사용할 수 있는 만큼만 사용하기로 하였습니다.
가로의 길이 W와 세로의 길이 H가 주어질 때, 사용할 수 있는 정사각형의 개수를 구하는 solution 함수를 완성해 주세요.

제한사항
W, H : 1억 이하의 자연수
입출력 예
W	H	result
8	12	80
입출력 예 설명
입출력 예 #1
가로가 8, 세로가 12인 직사각형을 대각선 방향으로 자르면 총 16개 정사각형을 사용할 수 없게 됩니다. 원래 직사각형에서는 96개의 정사각형을 만들 수 있었으므로, 96 - 16 = 80 을 반환합니다.



*/